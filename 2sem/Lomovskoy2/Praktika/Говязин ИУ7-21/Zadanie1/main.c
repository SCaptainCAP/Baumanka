// Программа, которая умножает вводимое число на 8

#include<stdio.h>
#define multi 8 // Переназначаем слово multi на 8 для удобства изменения кода

int global = 5;

int arra[5];

int initi[3] = {1,2,3};

float multiplicate(float a, float b)
{
	return a * b; // Перемножаем аргументы функции
}

int main(void)
{
    float x; // Объявляем переменную с плавающей точкой
    printf("Input number to multi: "); // Подсказываем пользователю, что надо ввести число
    scanf("%f", &x); // Считываем введенное число
    x = multiplicate(x,multi);
    printf("Result: %f\n",x); // Выводим результат на экран
    return 0; // Возвращаем 0 - сигнализируем об успешном выполнении
}
