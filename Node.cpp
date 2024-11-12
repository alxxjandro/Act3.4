#include "Node.h"
#include <string>

template<class T>
Node<T>::Node(){
    key = 1;
    left = right = nullptr;
    ip;
}
template<class T>
Node<T>::Node(T value){
    key = 1;
    data = value;
    left = right =nullptr;
    ip;
}

template<class T>
void Node<T>::insertValue(T dataValue) {

    if (dataValue == data){
        this->key +=1;
        return; // para q no se dupliquen
    }

    if (dataValue < data){
        if(left == nullptr){
            left = new Node<T>(dataValue);
        }else {
            left->insertValue(dataValue);
        }
    } if (dataValue > data){
        if (right == nullptr){
            right = new Node<T>(dataValue);
        }else{
            right->insertValue(dataValue);
        }
    }
}

template class Node<int>;
template class Node<std::string>;