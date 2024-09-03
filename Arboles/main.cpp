#include <iostream>
#include "Tree.h"
using namespace std;

int main () {
    Node *tree = NULL;

    insertNode (tree, 8);
    insertNode (tree, 3); 
    insertNode (tree, 1);
    insertNode (tree, 6);
    insertNode (tree, 4);
    insertNode (tree, 7);
    insertNode (tree, 10);
    insertNode (tree, 14);
    isNodeHere(tree, 13);
    isNodeHere(tree, 1);
    insertNode (tree, 13);
    isNodeHere(tree, 13);
    preOrder(tree);
    cout<<"\n";
    postOrder(tree);
    cout<<"\n";
    inOrder(tree);
    cout<<"\n";
    return 0;
};