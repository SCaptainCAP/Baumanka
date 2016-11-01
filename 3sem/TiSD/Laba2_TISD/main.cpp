#include "StackArray.cpp"
#include "StackListKostyl.cpp"
#include <iostream>
#include <string>
#include <chrono>

#define ERROR_OK 0
#define ERROR_MEMORY 1
#define ERROR_LOOP 2

#define MODE_LIST 0
#define MODE_ARRAY 1


void printHelp()
{
    std::cout << ("Инструкция по работе со стеком\n\n");
    std::cout << ("Введите help для получения этой инструкции\n");
    std::cout << ("Введите switch для переключения между реализациями стеком и списком\n");
    std::cout << ("Введите exit для выхода из программы\n\n");

    std::cout << ("При работе с реализацией МАССИВОМ:\n");
    std::cout << ("Введите push [addr] для добавления какого-либо адреса\n");
    std::cout << ("Введите pop для взятия адреса из стека\n");
    std::cout << ("Введите print для печати стека\n");
    std::cout << ("Введите printa для печати адресов стека\n");
    std::cout << ("Введите empty для проверки стека на пустоту\n");
    std::cout << ("Введите get [i] для просмотра какого-либо элемента в стеке\n");
    std::cout << ("Введите addr [i] для просмотра адреса какого-либо элемента в стеке\n");
    std::cout << ("Введите size для просмотра количества элементов\n\n");

    std::cout << ("При работе с реализацией СПИСКОМ:\n");
    std::cout << ("Введите push для добавления элемента\n");
    std::cout << ("Введите print для печати стека\n");
    std::cout << ("Введите printa для печати адресов стека\n");
    std::cout << ("Введите printfree для печати освобожденных адресов\n");
    std::cout << ("Введите pop для взятия адреса из стека\n");
    std::cout << ("Введите empty для проверки стека на пустоту\n");
    std::cout << ("Введите get [i] для просмотра какого-либо элемента в стеке\n");
    std::cout << ("Введите addr [i] для просмотра адреса какого-либо элемента в стеке\n");
    std::cout << ("Введите size для просмотра количества элементов\n\n");
}

void handleException(std::runtime_error e)
{
    std::cout << e.what() << std::endl;
    exit(EXIT_FAILURE);
}

int main() {
    int size = 0;
    int *addr = NULL;
    int num = 0;
    int loop = 1;
    bool mode = MODE_ARRAY;
    std::string input = "";

    auto start = std::chrono::high_resolution_clock::now();
    auto start1 = std::chrono::high_resolution_clock::now();
    auto finish = std::chrono::high_resolution_clock::now();
    auto finish1 = std::chrono::high_resolution_clock::now();

    StackArray<int*> stackArray;
    StackListKostyl<int*> stackList;

    std::cout << ("ДЕМОНСТРАЦИОННАЯ ВЕРСИЯ СТЕКА v1.0\n\n");
    std::cout << ("Используется 2 реализации стека: массивом и списком\n\n");

    printHelp();
    std::cout << "\nРежим переключен на реализацию ";
    if (mode == MODE_ARRAY)
        std::cout << "МАССИВОМ\n";
    else
        std::cout << "СПИСКОМ\n";

    while (true) {
        try {
            loop = 1;
            std::cout << ">";
            std::cin.unsetf(std::ios::hex);
            std::cin.setf(std::ios::dec);
            std::cin >> input;

            if (input == "exit")
                break;

            if (input == "help")
            {
                printHelp();
                continue;
            }

            if (input == "switch") {
                mode = !mode;
                std::cout << "Режим переключен на реализацию ";
                if (mode == MODE_ARRAY)
                    std::cout << "МАССИВОМ\n";
                else
                    std::cout << "СПИСКОМ\n";
                continue;
            }

            if (mode == MODE_ARRAY) {
                if (input == "pop")
                {
                    start = std::chrono::high_resolution_clock::now();
                    addr = stackArray.Pop();
                    finish = std::chrono::high_resolution_clock::now();
                    std::cout << "Взятый элемент: " << addr <<std::endl;
                    //std::cout << "Время выполнения: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " наносекунд\n";
                    continue;
                }
                if (input == "push")
                {
                    std::cin.unsetf(std::ios::dec);
                    std::cin.setf(std::ios::hex);
                    if (!(std::cin >> num)) {
                        std::cin.clear();
                        std::cin.ignore(512, '\n');
                        std::cout << "Добавляем случайный адрес\n";
                        num = rand();
                    }
                    addr = (int *) num;

                    start = std::chrono::high_resolution_clock::now();
                    stackArray.Push(addr);
                    finish = std::chrono::high_resolution_clock::now();
                    //std::cout << "Время выполнения: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " наносекунд\n";
                    continue;
                }
                if (input == "get")
                {
                    std::cin >> num;
                    std::cout << "Взятый элемент: " << stackArray[num] << std::endl;
                    continue;
                }
                if (input == "empty")
                {
                    if (stackArray.IsEmpty())
                        std::cout << "Стек пустой" << std::endl;
                    else
                        std::cout << "Стек не пустой" << std::endl;
                    continue;
                }
                if (input == "addr")
                {
                    std::cin >> num;
                    std::cout << "Взятый адрес: " << stackArray.getAddr(num) << std::endl;
                    continue;
                }
                if (input == "size")
                {
                    std::cout << stackArray.Size() << std::endl;
                    continue;
                }
                if (input == "print")
                {
                    stackArray.print();
                    continue;
                }
                if (input == "printfree")
                {
                    std::cout << "Эта операция не применима к стеку на массиве" << std::endl;
                    continue;
                }
                if (input == "printa")
                {
                    stackArray.printAdresses();
                    continue;
                }
                if (input == "test")
                {
                    loop = -1;
                    std::cin >> loop;
                    assert(loop > 0);
                    start1 = std::chrono::high_resolution_clock::now();
                    for (int i = 0; i < loop; i++)
                    {
                        addr = (int *) rand();
                        stackArray.Push(addr);
                    }
                    finish1 = std::chrono::high_resolution_clock::now();
                    start = std::chrono::high_resolution_clock::now();
                    for (int i = 0; i < loop; i++)
                    {
                        stackArray.Pop();
                    }
                    finish = std::chrono::high_resolution_clock::now();
                    std::cout << "Добавление " << loop << " элементов..." << std::endl;
                    std::cout << "Время добавления: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish1-start1).count() << " наносекунд\n";
                    std::cout << "Удаление " << loop << " элементов..." << std::endl;
                    std::cout << "Время удаления: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " наносекунд\n";
                    std::cout << "Общее время: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start1).count() << " наносекунд\n";
                    continue;
                }
            }
            else {
                if (input == "pop")
                {
                    start = std::chrono::high_resolution_clock::now();
                    addr = stackList.Pop(true);
                    finish = std::chrono::high_resolution_clock::now();
                    std::cout << "Взятый элемент: " << addr <<std::endl;
                    //std::cout << "Время выполнения: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " наносекунд\n";
                    continue;
                }
                if (input == "push")
                {
                    start = std::chrono::high_resolution_clock::now();
                    stackList.Push(true);
                    finish = std::chrono::high_resolution_clock::now();
                    //std::cout << "Время выполнения: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " наносекунд\n";
                    continue;
                }
                if (input == "get")
                {
                    std::cin >> num;
                    std::cout << "Взятый элемент: " << stackList[num] << std::endl;
                    continue;
                }
                if (input == "empty")
                {
                    if (stackList.IsEmpty())
                        std::cout << "Стек пустой" << std::endl;
                    else
                        std::cout << "Стек не пустой" << std::endl;
                    continue;
                }
                if (input == "addr")
                {
                    std::cin >> num;
                    std::cout << "Взятый адрес: " << stackList.getAddr(num) << std::endl;
                    continue;
                }
                if (input == "size")
                {
                    std::cout << stackList.Size() << std::endl;
                    continue;
                }
                if (input == "print")
                {
                    stackList.print();
                    continue;
                }
                if (input == "printa")
                {
                    stackList.printAdresses();
                    continue;
                }
                if (input == "printfree")
                {
                    stackList.printFreeObl();
                    continue;
                }
                if (input == "test")
                {
                    loop = -1;
                    std::cin >> loop;
                    assert(loop > 0);
                    start1 = std::chrono::high_resolution_clock::now();
                    for (int i = 0; i < loop; i++)
                    {
                        addr = (int *) rand();
                        stackList.Push(false);
                    }
                    finish1 = std::chrono::high_resolution_clock::now();
                    start = std::chrono::high_resolution_clock::now();
                    for (int i = 0; i < loop; i++)
                    {
                        stackList.Pop(false);
                    }
                    finish = std::chrono::high_resolution_clock::now();
                    std::cout << "Добавление " << loop << " элементов..." << std::endl;
                    std::cout << "Время добавления: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish1-start1).count() << " наносекунд\n";
                    std::cout << "Удаление " << loop << " элементов..." << std::endl;
                    std::cout << "Время удаления: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " наносекунд\n";
                    std::cout << "Общее время: " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start1).count() << " наносекунд\n";
                    continue;
                }
            }

            std::cout << ("Неизвестная команда\n");
            std::cin.ignore(INT8_MAX, '\n');


        }
        catch (std::runtime_error e)
        {
            handleException(e);
        }


    }
}
