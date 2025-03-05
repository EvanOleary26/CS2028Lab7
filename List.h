#ifndef __LIST__H
#define __LIST__H

#include "Node.h"

template <class T>
class List {
    private:
        Node<T>* first;
        Node<T>* last;
        int length;
        int location;
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

	Data <T> GetItem(T target) {
		Node *temp = first;
		if (first == nullptr) {
	//Check if list is empty
			return nullptr;
		}
		if (first->data == target) {
		//Check if the first item in the list is the one that should be removed
			length--;
			if (first->next == nullptr) {
				//If there is only one item in the list
				first=nullptr;
				last=nullptr;
				return temp->data;
			} else {
				//If there is more than one item in the list
				T hold = first->data;
				first=first->next;
				temp=temp->next;
				temp->prev = nullptr;
				return hold;
			}
			while (temp->data != target && temp->next != nullptr) {
				//Move through the list while not at the item to remove or at the end
				temp = temp->next;
			}
			if (temp->next == nullptr && temp->data != target) {
				//Check if the loop got to the end of the list without finding the item
				return nullptr;
			}
			if (temp->next == nullptr && temp->data == target) {
			//Check if the last item in the list is the target
				last = temp->prev;
			}
			//Connect previous to next and next to previous then return the value of the item removed
			Node *placeholder = temp->prev;
			temp->prev = temp->next;
			temp->next = placeholder;
			delete placeholder;
			length--;
			return temp;
		}
	}

        bool IsInList(T target) {
            Node<T> temp = first;
            bool found = 0
            while (temp != nullptr && temp->data != inVal) {
                temp = temp->next;
                if (temp->data == target) {
                    found = true;
                    break;
                }
            }
            return found;
        }

        bool IsEmpty() {
            return length == 0
        }

    	int Size() {
		return length;
	}
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

        T SeeAt(int target) {
            Node<T> temp = first;
            for (i = 0; i < target; i++) {
                temp = temp->next;
                if (temp == nullptr) {
                    //throw exception
                }
            }
            location = temp->data;
            return location;
        }
        void Reset(int &location) {
            location = 0;
        }

        //Operator Overloads
        /*
        bool operator<(const List<T> &right) const;
        bool operator>(const List<T> &right) const;
        bool operator==(const List<T> &right) const;
        */
};

#endif
