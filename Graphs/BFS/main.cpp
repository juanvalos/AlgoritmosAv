/*
Created by Juan Avalosx
18 / 08 / 2024
*/

# include "BFS.h"

int main() 
{
    int n = 5;  // Número de nodos
    vector<int> adj[n];  // Creamos una lista de adyacencia con n nodos
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector<int> ans = bfsOfGraph(n, adj, 0);
    printVector(ans);

    return 0;
}