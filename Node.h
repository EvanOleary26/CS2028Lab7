#ifndef __NODE__H
#define __NODE__H

#include "List.h"

template<class T>
class Node {
    public:
        T data;
        Node<T> *next;
        Node<T>*prev;
        //Constructors
        Node() : data(0), next(nullptr), prev(nullptr) {};
        Node(T inVal) : data(inVal), next(nullptr), prev(nullptr) {};

        templacefriend List;
};









#endif