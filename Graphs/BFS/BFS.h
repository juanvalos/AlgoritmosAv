/*
Created by Juan Avalosx
18 / 08 / 2024
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int numNodes, vector<int> adj[], int initialNode) {
        
    vector<int> vis(numNodes, 0);  // Creamos un vector de tamaño numNodes y el valor default de todos los índices será 0
    vis[initialNode] = 1;  // Marcamos el nodo inicial como visitado
        
    // Creamos la queue donde se almacenaran los nodos que estan en la lista de adjacencia del nodo visitado
    queue<int> q;
    q.push(initialNode);
        
    vector<int> bfs; 
        
    while(!q.empty()) {
        int currentNode = q.front(); 
        q.pop(); 
        bfs.push_back(currentNode); 
        
        for(auto i : adj[currentNode]) {
            // Si el vecino no ha sido visitado
            if(!vis[i]) { 
                // Marcamos como visitado y lo agregamos al queue q
                vis[i] = 1;  
                q.push(i);
            }
        }
    }

    return bfs; 
    
};

// Agregar edges a una adjacency list
void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
};

// Mostrar en terminal el vector solicitado
void printVector(vector <int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}; 