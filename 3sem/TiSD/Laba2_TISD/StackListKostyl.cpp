#include <iostream>
#include <assert.h>
#include <vector>

template <typename T>
struct Node
{
    T Data;
    Node* Next;

};

template <class T>
class StackListKostyl {
public:
    StackListKostyl();
    ~StackListKostyl();

    void Push(bool arFree);
    T Pop(bool arFree);
    T operator[] (int i);
    T get(int i);
    T* getAddr(int i);
    bool IsEmpty() const;
    int Size() const;

    void print() const;
    void printFreeObl() const;
    void printAdresses() const;

protected:
    Node<T>* start;
    std::vector<Node<T>*> freeObl;
};


template <typename T>
StackListKostyl<T>::StackListKostyl() : start(0){}


template <typename T>
StackListKostyl<T>::~StackListKostyl()
{
    while (!IsEmpty() )
    {
        Pop(false);
    }
}


template <typename T>
void StackListKostyl<T>::Push(bool arFree) {
    Node<T>* newNode = new(std::nothrow) Node<T>;
    if (newNode == NULL)
    {
        throw std::runtime_error("ERROR: Not enough memory");
    }
    else
    {
        if (arFree) {
            for (int i = 0; i < freeObl.size(); i++) {
                if (freeObl[i] == newNode) {
                    freeObl.erase(freeObl.begin() + i);
                    break;
                }
            }
        }
        newNode->Data = (int*) newNode;
        newNode->Next = start;
        start = newNode;
    }
}


template <typename T>
T StackListKostyl<T>::Pop(bool arFree) {
    if (IsEmpty())
        throw std::runtime_error("ERROR: popBack from empty stack");
    T data = start->Data;
    Node<T>* node_tmp = start;
    start = start->Next;
    if (arFree)
        freeObl.push_back(node_tmp);
    free(node_tmp);
    return data;
}


template <typename T>
bool StackListKostyl<T>::IsEmpty() const
{
    return (start == NULL);
}

template <typename T>
int StackListKostyl<T>::Size() const
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
T StackListKostyl<T>::operator[](int i) {
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
T StackListKostyl<T>::get(int i) {
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
T* StackListKostyl<T>::getAddr(int i) {
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
void StackListKostyl<T>::print() const {
    Node<T>* tmp = start;
    while (tmp) {
        std::cout << tmp->Data << std::endl;
        tmp = tmp->Next;
    }
}

template <typename T>
void StackListKostyl<T>::printFreeObl() const {
    for (int i = 0; i < freeObl.size(); i++) {
        std::cout << freeObl[i] << std::endl;
    }
}

template <typename T>
void StackListKostyl<T>::printAdresses() const {
    Node<T>* tmp = start;
    while (tmp) {
        std::cout << tmp << std::endl;
        tmp = tmp->Next;
    }
}
