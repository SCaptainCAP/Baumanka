#include <iostream>

#include <iostream>
#include <assert.h>

template <typename T>
struct Node
{
    T Data;
    Node* Next;
    Node() : Next(0){}
    Node(T data) : Next(0){}

};

template <class T>
class Stack {
public:
    Stack();
    ~Stack();

    T operator[](int i);
    T get(int i);
    T* getAddr(int i);
    void PushBack(T data);
    T PopBack();
    bool IsEmpty() const;

private:
    Node<T>* start;
};


template <typename T>
Stack<T>::Stack() : start(0){}


template <typename T>
Stack<T>::~Stack()
{
    while (!IsEmpty() )
    {
        PopBack();
    }
}


template <typename T>
void Stack<T>::PushBack(T data) {
    Node<T>* newNode = new(std::nothrow) Node<T>(data);
    if (newNode == NULL)
    {
        throw std::runtime_error("ERROR: indexing out of range of buffer");
    }
    else
    {
        newNode->Data = data;
        if (IsEmpty()) {
            start = newNode;
            return;
        }
        Node<T>* node_tmp = start;
        while (node_tmp->Next != NULL)
            node_tmp = node_tmp->Next;
        node_tmp->Next = newNode;
    }
}


template <typename T>
T Stack<T>::PopBack() {
    if (IsEmpty())
        throw std::runtime_error("ERROR: popBack from empty stack");
    Node<T>* node_tmp = start;
    Node<T>* prev = start;
    while (node_tmp->Next != NULL) {
        prev = node_tmp;
        node_tmp = node_tmp->Next;
    }
    T data = node_tmp->Data;
    if (prev == node_tmp) { //last element popped
        free(node_tmp);
        start = NULL;
    }
    else {
        free(node_tmp);
        prev->Next = NULL;
    }
    return data;
}


template <typename T>
bool Stack<T>::IsEmpty() const
{
    return (start == 0);
}

template <typename T>
T Stack<T>::operator[](int i) {
    Node<T>* node_tmp = start;
    int j = 0;
    while (i < j || node_tmp->Next != NULL) {
        node_tmp = node_tmp->Next;
        j++;
    }
    if (i == j)
        return node_tmp->Data;
    else
        throw std::runtime_error("ERROR: indexing out of range of buffer");
}

template <typename T>
T Stack<T>::get(int i) {
    Node<T>* node_tmp = start;
    int j = 0;
    while (i < j || node_tmp->Next != NULL) {
        node_tmp = node_tmp->Next;
        j++;
    }
    if (i == j)
        return node_tmp->Data;
    else
        throw std::runtime_error("ERROR: indexing out of range of buffer");
}

template <typename T>
T* Stack<T>::getAddr(int i) {
    Node<T>* node_tmp = start;
    int j = 0;
    while (i < j || node_tmp->Next != NULL) {
        node_tmp = node_tmp->Next;
        j++;
    }
    if (i == j)
        return &node_tmp->Data;
    else
        throw std::runtime_error("ERROR: indexing out of range of buffer");
}


