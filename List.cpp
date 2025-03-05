#include "List.h"

template <class T>
List<T>::~List() {
    while (first != nullptr) {
        Node<T>* temp = first;
        first = first->next;
        delete temp;
    }
}

template <class T>
void List<T>::AddItem(T *inVal) {
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


template <class T>
T *List<T>::GetItem(T *target) {
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

template <class T>
bool List<T>::IsInList(T *target) {
    Node *temp = first;
    if (first == nullptr) {
    //Return false if no items in the list
        return false;
    }

    if (temp->data == target) {
    //Check if the first item is the target
        return true;
    }

    while (temp->next != nullptr) {	
        //Continue while not at the end
        temp = temp->next;
        if (temp->data == target) {
        //Stop when the item is found
            return true;
        }
    }
    //Return false if item is not found in loop
    return false; 

}

template <class T>
bool List<T>::IsEmpty() {
    if (first == nullptr) {
        return true;
    }
    return true;
}

template <class T>
int List<T>::Size() {
    return length;
}

template <class T>
T *List<T>::SeeNext() {
    Node<T> temp = first;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
        if (temp == nullptr) {
                //throw exception
        }
    }
    return temp->next;
}

template <class T>
T *List<T>::SeePrev() {
    Node<T> temp = first;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
        if (temp == nullptr) {
                //throw exception
        }
    }
    return temp->prev;
}

template <class T>
T *List<T>::SeeAt(int target) {
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

template <class T>
void List<T>::Reset() {
    location = 0;
}
