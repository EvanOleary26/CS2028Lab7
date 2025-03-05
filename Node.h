#ifndef __NODE__H
#define __NODE__H

template<class T>
class Node {
    public:
        T data;
        Node *next;
        Node *prev;
    
        //Constructors
        Node() : data(0), next(nullptr), prev(nullptr) {};
        Node(T inVal) : data(inVal), next(nullptr), prev(nullptr) {};
};









#endif