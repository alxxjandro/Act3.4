#ifndef ACT3_4_NODE_H
#define ACT3_4_NODE_H
#include <string>

template<class T>
class Node {
public:
    int key;
    T data;
    std::string ip;
    Node* left;
    Node* right;
    Node();
    Node(T dataValue);
    void insertValue(T dataValue);
    void setIP(std::string ip);
};

template<class T>
void Node<T>::setIP(std::string ip) {
    this->ip = ip;
}


#endif