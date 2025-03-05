#ifndef __LIST__H
#define __LIST__H

#include "Node.h"

template <class T>
class List {
    private:
        Node<T>* first;
        Node<T>* last;
        int length;
    public:
        //Constructors
        List() : first(nullptr), last(nullptr), length(0) {};

        //Destructor
        ~List();

        //Functions
        void AddItem(T inVal) {
            Node<T>* newNode = new Node<T>(inVal);
            if (first == nullptr) {
                first = newNode;
                last = newNode;
            }
            else {
                Node<T>* temp = first;
                while (temp != nullptr) {
                    if (inVal < temp->data) {
                        newNode->next = temp;
                        newNode->prev = temp->prev;
                        if (temp->prev != nullptr) {
                            temp->prev->next = newNode;
                        }
                        else {
                            first = newNode;
                            break;
                        }
                    }
                    else if (temp->next == nullptr) {
                        temp->next = newNode;
                        newNode->prev = temp;
                        last = newNode;
                        break;
                    }
                    temp = temp->next;
                }
            }
            length++;
        }
        /*
        T GetItem(T target);
        bool IsInList(T target);
        bool IsEmpty();
        int Size();
        T SeeNext();
        T SeePrev();
        void Reset();
        */
        T SeeNext(T target) {
            Node<T> temp = first;
            while (temp != nullptr && temp->data != target) {
                temp = temp->next;
                if (temp == nullptr) {
                    //throw exception
                }
            }
        return temp->next;
        }
        T SeePrev(T target) {
            Node<T> temp = first;
            while (temp != nullptr && temp->data != target) {
                temp = temp->next;
                if (temp == nullptr) {
                    //throw exception
                }
            }
            return temp->prev;
        }
        T SeeAt(int location) {
            Node<T> temp = first;
            for (i = 0; i < location; i++) {
                temp = temp->next;
                if (temp == nullptr) {
                    //throw exception
                }
            }
            return temp->data;
        }

        //Operator Overloads
        /*
        bool operator<(const List<T> &right) const;
        bool operator>(const List<T> &right) const;
        bool operator==(const List<T> &right) const;
        */
};

#endif
