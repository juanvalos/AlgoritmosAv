# include <iostream>
# include <string>
# include <fstream>
# include <vector>

using namespace std;

// Converts a .txt file into a vector, in each vector index is a line of the .txt file
void txtToVec (ifstream& txt, vector <string>& vec){
    for(string str; getline(txt, str, '\n'); ){
        vec.push_back(str);
    }
};

// Converts a .txt file into a string
void txtToString (ifstream& txt, string& str) {
    getline(txt, str);
};

// Checks if a substring is in a certain string
bool mcodeExists (string str, string substr) {
    return str.find(substr) != string::npos;
};

bool palindromeExists(string str){

};

// Shows in terminal where a substring starts and finishes on a certain string
void stringCount (string& str, string& substr){
    size_t inicio = str.find(substr);
    size_t fin = inicio + substr.length() - 1;
    cout << "  chars from "<< inicio << " to " << fin << "." << endl;
};

// Find malicious code in a transmission (Part1)
void malCodeTester(vector <string>& vec, string& malcode1, string& malcode2, string& malcode3) {
    string transm;
    string malcode;
    int flags[3] = {0,0,0};
    int line = 1;

    for (int i = 0; i < vec.size(); i++) {
        transm = vec[i];
        
        if (mcodeExists(transm, malcode1) == 1){
            malcode = malcode1;
            cout << "True  " << malcode << "  line: " << line + i;
            stringCount(transm, malcode);
            flags[0] = 1;
        }
        

        if (mcodeExists(transm, malcode2) == 1){
            malcode = malcode2;
            cout << "True  " << malcode << "  line: " << line + i;
            stringCount(transm, malcode);
            flags[1] = 1;
        }

        if (mcodeExists(transm, malcode3) == 1){
            malcode = malcode3;
            cout << "True  " << malcode << "  line: " << line + i;
            stringCount(transm, malcode);
            flags[2] = 1;
        }
    }

    if (flags[0] == 0){
        cout << "False  " << malcode1 << endl;
    }

    if (flags[1] == 0){
        cout << "False  " << malcode2 << endl;
    }

    if (flags[2] == 0){
        cout << "False  " << malcode3 << endl;
    }
};

void findPalindomesTester (vector <string>& vec){
    string transm;
    int flag = 0;

    for (int i = 0; i < vec.size(); i++){

    }
};