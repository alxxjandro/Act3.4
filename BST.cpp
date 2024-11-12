#include "BST.h"
#include <iostream>
#include <queue>
#include <map>
using namespace std;

template<class T>
BST<T>::BST() {
    root = nullptr;
}
template<class T>
Node<T>* BST<T>::getRoot() {
    Node<T>* temp = root;
    return temp;
}

template<class T>
void BST<T>::insertNode(T insertValue){
    //nomas para ver si es el primero, sino es el metodo de los nodos
    if (root == nullptr){
        root = new Node<T>(insertValue);
    } else{
        root->insertValue(insertValue);
    }
}

// ~ ~ ~ visit
template<class T>
void BST<T>::visit(int option) {
    Node<T>* aux = root;
    switch (option) {
        case 1:
            preorden(aux);
            break;
        case 2:
            inorder(aux);
            break;
        case 3:
            postorder(aux);
            break;
        case 4:
            nivel(aux);
            break;
        default:
            cerr << "Opción no valida :(" << endl;
            break;
    }
}

template<class T>
void BST<T>::preorden(Node<T> *node) {
    if (node == nullptr){
        return;
    } else{
        cout << node->data << endl;
        preorden(node->left);
        preorden(node->right);
    }
}

template<class T>
void BST<T>::inorder(Node<T> *node) {
    if (node == nullptr){
        return;
    } else{
        inorder(node->left);
        cout << node->data << endl;
        inorder(node->right);
    }
}

template<class T>
void BST<T>::postorder(Node<T> *node) {
    if (node == nullptr){
        return;
    }else{
        postorder(node->left);
        postorder(node->right);
        cout << node->data << endl;
    }
}

template<class T>
void BST<T>::nivel(Node<T> *node){
    if (node == nullptr) {
        return;
    }

    queue<Node<T>*> cola;
    cola.push(node);

    while (!cola.empty()) {
        Node<T>* actual = cola.front();
        cola.pop();
        cout << actual->data << endl;
        //pa q no haga error de segmentacion
        if (actual->left != nullptr) {
            cola.push(actual->left);
        }
        if (actual->right != nullptr) {
            cola.push(actual->right);
        }
    } cout << endl;
}


// ~ ~ ~ height

template<class T>
int BST<T>::height(Node<T> *node) {
    if (node == nullptr) {
        return -1;
    } else {
        //hacemos como tipo subarboles
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }
}

// ~ ~ ~ ancestors

template<class T>
bool BST<T>::ancestors(Node<T>* node, T target) {
    if (node == nullptr){
        return false;
    } if (node->data == target){
        return true;
    }

    //hay q checar si el target esta dentro del arbol izq/der y sisi, imprimir ese arbol
    if (ancestors(node->left,target) || ancestors(node->right,target) ){
        cout << node->data << endl;
        return true;
        // pa q no truene los demas y no solo imprima el ultimo
    }
    return false;
}

// ~ ~ ~ whatlevelamI

template<class T>
int BST<T>::whatlevelamI(Node<T>* node, T target, int lvl ) {
    if (node == nullptr) {
        return -1;
    }
    if (node->data == target) {
        return lvl;
    }
    int arbolIzq = whatlevelamI(node->left, target, lvl + 1);
    if (arbolIzq != -1) {
        return arbolIzq;
    }
    return whatlevelamI(node->right, target, lvl + 1);
}

template<class T>
void BST<T>::preordenDos(Node<T> *node, vector<pair<T,int>>* almacen) {
    if (node == nullptr) {
        return;
    } else {
        //cout << node->data << ' ' << node->key << endl;
        T test = node->data;
        almacen->push_back(make_pair(test,node->key));

        preordenDos(node->left, almacen);
        preordenDos(node->right, almacen);
    }
}




template class BST<int>;
template class BST<string>;
