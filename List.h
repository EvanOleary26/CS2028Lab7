#ifndef __LIST__H
#define __LIST__H

#include "Node.h"

template <class T>
class List {
    private:
        Node *first;
        Node *last;
        int length;
        int location;
    public:
        //Constructors
        List() : first(nullptr), last(nullptr), length(0) {};

        //Destructor
        ~List() {
            while (first != nullptr) {
                Node<T>* temp = first;
                first = first->next;
                delete temp;
            }
        }

        //Functions
        void AddItem(T *inVal);
        T *GetItem(T *target);
        bool IsInList(T *target);
        bool IsEmpty();
        int Size();
        T *SeeNext();
        T *SeePrev();
        T *SeeAt(int target);
        void Reset();

        //Operator Overloads
        bool operator<(const List<T> &right) const;
        bool operator>(const List<T> &right) const;
        bool operator==(const List<T> &right) const;
};

#endif
