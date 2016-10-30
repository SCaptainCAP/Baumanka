#include "Stack.cpp"
#include <iostream>
#include <string>
int main() {
    int size = 0;
    int *addr = NULL;
    int num = 0;
    std::string input = "";

    Stack<int*> stack;
    printf("ДЕМОНСТРАЦИОННАЯ ВЕРСИЯ СТЕКА (РЕАЛИЗАЦИЯ ДИНАМИЧЕСКИМ МАССИВОМ\n");
    printf("Инструкция по работе со стеком\n");
    printf("Введите push [addr] для добавления какого-либо адреса\n");
    printf("Введите pop для взятия адреса из стека\n");
    printf("Введите addr [i] для просмотра адреса какого-либо элемента в стеке\n");
    printf("Введите get [i] для просмотра какого-либо элемента в стеке\n");
    printf("Введите exit для выхода из программы\n");

    while (true) {
        std::cin >> input;
        if (input == "exit")
            break;

        if (input == "pop")
        {
            addr = stack.PopBack();
            printf("Взятый элемент: %p\n", addr);
            continue;
        }
        if (input == "push")
        {
            std::cin.unsetf(std::ios::dec);
            std::cin.setf(std::ios::hex);
            std::cin >> num;
            addr = (int *)num;
            stack.PushBack(addr);
            printf("Элемент добавлен\n");
            continue;
        }
        if (input == "get")
        {
            std::cin >> num;
            printf("Взятый элемент: %p\n", stack[num]);
            continue;
        }
        if (input == "addr")
        {
            std::cin >> num;
            printf("Взятый адрес: %p\n", stack.getAddr(num));
            continue;
        }
        printf("Неизвестная команда\n");
    }
}
