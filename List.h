#ifndef __LIST__H
#define __LIST__H

template <class>
class List {
    private:
        Node<T> *head;
        Node<T> *tail;
        int length;
    public:
        //Constructors
        List() : head(nullptr), tail(nullptr), length(0) {};

        //Destructor
        ~List();

        //Functions
        void AddItem(T inVal);
        T GetItem(T target);
        bool IsInList(T target);
        bool IsEmpty();
        int Size();
        T SeeNext();
        T SeePrev();
        void Reset();

        //Operator Overloads
        bool operator<(const List<T> &right) const;
        bool operator>(const List<T> &right) const;
        bool operator==(const List<T> &right) const;
        

        

};

#endif