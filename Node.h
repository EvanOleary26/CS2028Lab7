#ifndef __NODE__H
#define __NODE__H

template<class>
class Node {
    private:
        T data;
        T *next;
        T *prev;
    public:
        //Constructors
        Node() : data(0), next(nullptr), prev(nullptr) {};
        Node(T data) : data(data), next(nullptr), prev(nullptr) {};
};









#endif