#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *right;
    Node *left;
};

Node *createNode (int); 
void insertNode(Node *&, int);
bool searchNode (Node *, int);
void isNodeHere (Node *, int);

Node *minLeft (Node *);
void replaceNode( Node *, Node *);
void delNode (Node *);
void deleteNode (Node *, int);

void preOrder (Node *);
void postOrder (Node *);
void inOrder (Node *);

// Funcion para crear un nuevo nodo
Node *createNode (int val) {
    Node *newNode = new Node();
    newNode -> value = val;
    newNode -> right = NULL;
    newNode -> left = NULL;
    return newNode;
};

// Funcion para insertar un nodo en un arbol
void insertNode (Node *&tree, int val){
    if (tree == NULL){ // Si el arbos esta vacio
        Node *newNode = createNode (val);
        tree = newNode;
    }
    else { // si el arbol tiene 1 o mas nodos
        int rootVal = tree -> value; // Obtenemos valor de la raiz del arbol
        if (val < rootVal) {
            insertNode(tree -> left, val);
        }
        if (val > rootVal) {
            insertNode(tree -> right, val);
        }
    }
};

// Funcion para buscar un elemento en un arbol.
bool searchNode (Node *tree, int val){
    if (tree == NULL){
        return false;
    }
    else if (tree -> value == val) {
        return true;
    }
    else if (val < tree -> value){
        return searchNode(tree -> left, val);
    }
    else if (val > tree -> value){
        return searchNode(tree -> right, val);
    }
    else {
        return false;
    }
};

//Funciòn para desplegar en terminal que el nodo no está c
void isNodeHere (Node *tree, int val){
    bool search = searchNode(tree, val);
    if (search == true){
        cout << "The value " << val << " is in the tree" << endl;
    }
    else {
        cout << "The value " << val << " is NOT the tree" << endl;
    }
};

//Funcion que encuentra el minimo hijo izquierdo de un arbol(ayuda a eliminar un nodo con 2 hijos dentro de un arbol)
Node  *minLeft (Node *tree){
    if (tree == NULL) {
        return NULL;
    }
    else if (tree -> left){
        return minLeft(tree->left);
    }
    else {
        return tree;
    }
};

/*
// Funcion para remplazar 2 nodos
void replaceNode (Node *tree, Node *node){
    if (tree -> nodeAux) {

    }
};
// Funcion que elimina el nodo buscado
void delNode (Node *node) {
    if (node ->left && node -> right) {
        Node *minL = minLeft(node ->right);
        node -> value == minL ->value;
        delNode(minL);
    }
};

// Funcion que encuentra el nodo a eliminar
void deleteNode ( Node *tree, int val){
    if (tree == nullptr){
        return;
    }
    else if (tree -> value == val){
        delNode(tree);
    }
    else if (val < tree -> value) {
        deleteNode(tree -> left, val);
    }
    else if (val > tree -> value) {
        deleteNode(tree -> right, val);
    }
    else {
        cout << "El nodo que se quiso eliminar no esta dentro del arbol" << endl;
    }

}; 
*/

// Funcion para recorrer el arbol en Pre-Orden
void preOrder (Node *tree) {
    if (tree == nullptr){
        return;
    }
    else {
        cout << tree -> value << "  "; 
    }
    preOrder(tree -> left);
    preOrder(tree -> right);
};

// Funcion para recorrer el arbol en In-Orden
void inOrder (Node *tree) {
    if (tree == nullptr){
        return;
    }
    else {
        inOrder(tree -> left);
        cout << tree -> value << "  ";
        inOrder(tree -> right);
    }
};

// Funcion para recorrer el arbol en Post-Orden
void postOrder (Node *tree) {
    if (tree == nullptr){
        return;
    }
    else {
        postOrder(tree -> left);
        postOrder(tree -> right);
        cout << tree -> value << "  ";
    }
};