 # include <iostream>
# include  <vector>
# include <functional>
using namespace std;

// Creamos la clase nodo node Giadamos la key, el value, y el apuntadot al siguiente nodo.
class Node {
    public:
        int key;
        int value;
        Node* next;

        // Constructor
        Node (int key, int value) {
            this -> key = key;
            this -> value = value;
            this -> next = NULL;
        }

};

// Definimos la clase HashMap
class hashTable {
    
    private: 
        // Vector donde guardaremos todos los nodos (Buckets)
        vector <Node*> buckets;
        
        int sizee;
        int numBuckets;
        
        double DEFAULT_LOAD_FACTOR = 0.8;

        // funcion para calcular el indice del bucket en donde se va a
        int getBucketInd (int key) {
            int hashCode = hash<int>()(key);
            return hashCode % numBuckets;
        }
    
    public:
        hashTable () {
            int sizee = 0;
            numBuckets = 5;
            buckets.resize(numBuckets);

            cout << "HashMap created" << endl;
            cout << "Number of pairs in the Map: " << sizee << endl;
            cout << "Size of Map: " << numBuckets << endl;
            cout << "Default Load Factor : " << DEFAULT_LOAD_FACTOR << endl;
        }

        void insert (int key, int value) {
            int bucketIndex = getBucketInd(key);
            Node* head = buckets [bucketIndex];


            while ( head != NULL) {
                if (head -> key == key) {
                    head -> value = value;
                    return;
                }

                head = head -> next;
            }

            Node* newNode = new Node (key, value);
            head = buckets[bucketIndex];
            newNode -> next = head;
            buckets [bucketIndex] = newNode;

            cout << "Pair(" << key << ", " << value << ") inserted successfully." << endl;

            sizee = sizee +1;

            double loadFactor = (1 * sizee) / numBuckets;

            cout << "Current Load factor = " << loadFactor << endl;
            cout << sizee << endl;
            cout << numBuckets << endl;

            if (loadFactor > DEFAULT_LOAD_FACTOR) {
                cout << loadFactor << " is greater than " << DEFAULT_LOAD_FACTOR << endl;
                cout << "Rehashing will be done." << endl;

                rehash ();
                cout << "New Size of Map: " << numBuckets << endl;
            }
 
            cout << "Number of pairs in the Map: " << sizee << endl;

        }

    void rehash() {
        cout << "\n***Rehashing Started***\n" << endl;
    
        // The present bucket list is made temp
        vector <Node*> temp = buckets;
    
        // New bucketList of double the old size is created
        buckets.resize(2 * numBuckets);
    
        for (int i = 0; i < 2 * numBuckets; i++) {
            // Initialized to null
            buckets[i] = NULL;
        }
    
        // Now size is made zero
        // and we loop through all the nodes in the original bucket list(temp)
        // and insert it into the new list
        sizee = 0;
        numBuckets *= 2;
    
        for (int i = 0; i < temp.size(); i++) {
            // head of the chain at that index
            Node* head = temp[i];
    
            while (head != NULL) {
                int key = head->key;
                int val = head->value;
    
                // calling the insert function for each node in temp
                // as the new list is now the bucketArray
                insert(key, val);
                head = head->next;
            }
        }
    
        cout << "***Rehashing Done***\n" << endl;
    }
};