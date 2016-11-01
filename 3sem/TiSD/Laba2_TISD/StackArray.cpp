#include <iostream>


#define DEFAULT_SIZE 1000000000
#define INCREASE_COEF 2
#define MEMMOVE 0


template <class T>
class StackArray {
public:
    StackArray(int size);
    StackArray();
    ~StackArray();

    void Push(T data);
    T Pop();
    T operator[] (int i);
    T get(int i);
    T* getAddr(int i);
    bool IsEmpty() const;
    int Size() const;

    void print() const;
    void printAdresses() const;

private:
    T* buffer = NULL;
    int bufferSize;
    int minBufferSize;
    int tail;
    void IncreaseBuffer();
    void DecreaseBuffer();
};

template <typename T>
StackArray<T>::StackArray(int size) : bufferSize(size), minBufferSize(size), tail(-1)
{
    if (size < 2)
        throw std::runtime_error("ERROR: StackArray default size cannot be < 2");
    buffer = new T[bufferSize];
}

template <typename T>
StackArray<T>::StackArray() : bufferSize(DEFAULT_SIZE), minBufferSize(DEFAULT_SIZE), tail(-1)
{
    buffer = new T[bufferSize];
}

template <typename T>
StackArray<T>::~StackArray()
{
    delete[](buffer);
}

template <typename T>
void StackArray<T>::IncreaseBuffer() {
    T* tmpBuffer = new(std::nothrow) T[(bufferSize * INCREASE_COEF)];
    //assert(tmpBuffer);
    if (tmpBuffer == NULL)
        throw std::runtime_error("ERROR: Not enough memory");

    if (!MEMMOVE) {
        for (int i = 0; i < bufferSize; i++) {
            tmpBuffer[i] = buffer[i];
        }
    }
    else

    bufferSize *= INCREASE_COEF;

    delete [](buffer);
    buffer = tmpBuffer;
}

template <typename T>
void StackArray<T>::DecreaseBuffer() {
    T* tmpBuffer = new(std::nothrow) T[(bufferSize / INCREASE_COEF)];
    if (tmpBuffer == NULL)
        throw std::runtime_error("ERROR: Not enough memory");

    for (int i = 0; i < bufferSize / INCREASE_COEF; i++)
    {
        tmpBuffer[i] = buffer[i];
    }
    bufferSize /= INCREASE_COEF;

    delete [](buffer);
    buffer = tmpBuffer;
}

template <typename T>
void StackArray<T>::Push(T data) {
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
T StackArray<T>::Pop() {
    if (IsEmpty())
        throw std::runtime_error("ERROR: popBack from empty stack");
    T data = buffer[tail];
    tail--;
    if (tail < bufferSize / INCREASE_COEF  && bufferSize > minBufferSize)
    {
        DecreaseBuffer();
    }
    return data;
}

template <typename T>
bool StackArray<T>::IsEmpty() const
{
    return tail == -1;
}

template <typename T>
int StackArray<T>::Size() const
{
    return tail + 1;
}

template <typename T>
void StackArray<T>::print() const {
    for (int i = 0; i < tail + 1; i++)
    {
        std::cout << buffer[i] << std::endl;
    }
}

template <typename T>
void StackArray<T>::printAdresses() const {
    for (int i = 0; i < tail + 1; i++)
    {
        std::cout << &(buffer[i]) << std::endl;
    }
}

template <typename T>
T StackArray<T>::operator[](int i) {
    if (i < 0 || i > tail)
        throw std::runtime_error("ERROR: indexing out of range of buffer");
    return buffer[i];
}

template <typename T>
T StackArray<T>::get(int i) {
    if (i < 0 || i > tail)
        throw std::runtime_error("ERROR: indexing out of range of buffer");
    return buffer[i];
}

template <typename T>
T* StackArray<T>::getAddr(int i) {
    if (i < 0 || i > tail)
        throw std::runtime_error("ERROR: indexing out of range of buffer");
    return &buffer[i];
}


