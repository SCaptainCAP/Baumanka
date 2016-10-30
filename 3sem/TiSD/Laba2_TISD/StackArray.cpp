#include <iostream>


#define DEFAULT_SIZE 4

#define ERROR_INCREASING_BUFFER 100
#define ERROR_DECREASING_BUFFER 101

template <class T>
class Stack {
public:
    Stack(int size);
    Stack();
    ~Stack();

    int PushBack(T data);
    T PopBack();
    T operator[] (int i);
    T get(int i);
    T* getAddr(int i);
    bool IsEmpty() const;

    void print(bool debug = false) const;

private:
    T* buffer = NULL;
    int bufferSize;
    int minBufferSize;
    int tail;
    int IncreaseBuffer();
    int DecreaseBuffer();
};

template <typename T>
Stack<T>::Stack(int size) : bufferSize(size), minBufferSize(size), tail(-1)
{
    if (size < 2)
        throw std::runtime_error("ERROR: Stack default size cannot be < 2");
    buffer = new T[bufferSize];
}

template <typename T>
Stack<T>::Stack() : bufferSize(DEFAULT_SIZE), minBufferSize(DEFAULT_SIZE), tail(-1)
{
    buffer = new T[bufferSize];
}

template <typename T>
Stack<T>::~Stack()
{
    delete[](buffer);
}

template <typename T>
int Stack<T>::IncreaseBuffer() {
    T* tmpBuffer = new(std::nothrow) T[(bufferSize * 2)];
    //assert(tmpBuffer);
    if (tmpBuffer == NULL)
        return ERROR_INCREASING_BUFFER;

    for (int i = 0; i < bufferSize; i++)
    {
        tmpBuffer[i] = buffer[i];
    }
    bufferSize *= 2;

    delete [](buffer);
    buffer = tmpBuffer;
}

template <typename T>
int Stack<T>::DecreaseBuffer() {
    T* tmpBuffer = new(std::nothrow) T[(bufferSize / 2)];
    if (tmpBuffer == NULL)
        return ERROR_DECREASING_BUFFER;

    for (int i = 0; i < bufferSize / 2; i++)
    {
        tmpBuffer[i] = buffer[i];
    }
    bufferSize /= 2;

    delete [](buffer);
    buffer = tmpBuffer;
}

template <typename T>
int Stack<T>::PushBack(T data) {
    if (IsEmpty()) {
        tail = 0;
        buffer[0] = data;
    }
    else
    {
        tail++;
        if (tail > bufferSize)
            IncreaseBuffer();
        buffer[tail] = data;
    }

}


template <typename T>
T Stack<T>::PopBack() {
    if (IsEmpty())
        throw std::runtime_error("ERROR: popBack from empty stack");
    T data = buffer[tail];
    tail--;
    if (tail < bufferSize / 2  && bufferSize > minBufferSize)
    {
        DecreaseBuffer();
    }
    return data;
}

template <typename T>
bool Stack<T>::IsEmpty() const
{
    return tail == -1;
}

template <typename T>
void Stack<T>::print(bool debug) const {
    std::cout << "|";
    for (int i = 0; i < bufferSize; i++)
    {
        std::cout << " " << buffer[i] << " |";
    }
}

template <typename T>
T Stack<T>::operator[](int i) {
    if (i < 0 || i > tail)
        throw std::runtime_error("ERROR: indexing out of range of buffer");
    return buffer[i];
}

template <typename T>
T Stack<T>::get(int i) {
    if (i < 0 || i > tail)
        throw std::runtime_error("ERROR: indexing out of range of buffer");
    return buffer[i];
}

template <typename T>
T* Stack<T>::getAddr(int i) {
    if (i < 0 || i > tail)
        throw std::runtime_error("ERROR: indexing out of range of buffer");
    return &buffer[i];
}


