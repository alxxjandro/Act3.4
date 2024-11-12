#ifndef ACT3_4_BST_H
#define ACT3_4_BST_H
#include "Node.h"
#include "BST.h"
#include <map>
using namespace std;

template<class T>
class BST {
private:
    Node<T>* root;
    void preorden(Node<T>* root);
    void inorder(Node<T>* root);
    void postorder(Node<T>* root);
    void nivel(Node<T>* root);
public:
    BST();
    Node<T>* getRoot();
    void insertNode(T intsertValuem);
    void visit(int option);
    int height(Node<T>* root);
    bool ancestors(Node<T>* root, T target);
    int whatlevelamI(Node<T>* nodo, T target, int contador);
    void preordenDos(Node<T> *node, vector<pair<T,int>>* almacen);

};




#endif
