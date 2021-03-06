#include <iostream>
#include <assert.h>

template <typename T>
struct Node
{
    T Data;
    Node* Next;
};

template <class T>
class StackList {
public:
    StackList();
    ~StackList();

    void Push(T data);
    T Pop();
    T operator[] (int i);
    T get(int i);
    T* getAddr(int i);
    bool IsEmpty() const;
    int Size() const;

    void print(bool debug = false) const;

protected:
    Node<T>* start;
};


template <typename T>
StackList<T>::StackList() : start(0){}


template <typename T>
StackList<T>::~StackList()
{
    while (!IsEmpty() )
    {
        Pop();
    }
}


template <typename T>
void StackList<T>::Push(T data) {
    Node<T>* newNode = new(std::nothrow) Node<T>;
    if (newNode == NULL)
    {
        throw std::runtime_error("ERROR: Not enough memory");
    }
    else
    {
        newNode->Data = data;
        newNode->Next = start;
        start = newNode;
    }
}


template <typename T>
T StackList<T>::Pop() {
    if (IsEmpty())
        throw std::runtime_error("ERROR: popBack from empty stack");
    T data = start->Data;
    Node<T>* node_tmp = start;
    start = start->Next;
    free(node_tmp);
    return data;
}


template <typename T>
bool StackList<T>::IsEmpty() const
{
    return (start == NULL);
}

template <typename T>
int StackList<T>::Size() const
{
    int ans = 0;
    Node<T>* tmp = start;
    while (tmp->Next) {
        tmp = tmp->Next;
        ans++;
    }
    return ans;
}

template <typename T>
T StackList<T>::operator[](int i) {
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
T StackList<T>::get(int i) {
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
T* StackList<T>::getAddr(int i) {
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

template <typename T>
void StackList<T>::print() const {
    Node<T>* tmp = start;
    while (tmp->Next) {
        std::cout << tmp->Data << std::endl;
        tmp = tmp->Next;
    }
}

template <typename T>
void StackList<T>::printAdresses() const {
    Node<T>* tmp = start;
    while (tmp->Next) {
        std::cout << tmp << std::endl;
        tmp = tmp->Next;
    }
}


