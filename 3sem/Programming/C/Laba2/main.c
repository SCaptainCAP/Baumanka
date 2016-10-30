#include <stdio.h>
#include "error_codes_and_defines.h"
#include "realization.h"

//Вычислить значение x[0] + x[0]*x[1] + x[0]*x[1]*x[2] + ... + x[0]*x[1]*x[2] ... x[m],
//где x[i] - элементы массива x из n элементов, m - индекс первого отрицательного элемента
//этого массива либо число n-1, если такого элемента в массиве нет.

void show_error_message(int error, int answer);
int main(int argc, char *argv[])
{
    FILE * in_file;
    int errorcode = ERROR_OK;

    if (argc != 2)
    {
        errorcode = ERROR_BAD_ARGUMENT_COUNT;
    }

    if (errorcode == ERROR_OK)
    {
        in_file = fopen(argv[1], "r");
        if (in_file == NULL)
        {
            errorcode = ERROR_IN_FILE;
        }
    }

    int answer = 0;
    if (errorcode == ERROR_OK)
    {
        errorcode = sdelat_labu(in_file, &answer);
        fclose(in_file);
    }

    show_error_message(errorcode, answer);
    return errorcode;
}

void show_error_message(int error, int answer)
{
    if (error == ERROR_BAD_ARGUMENT_COUNT)
        printf("Bad argument count\n");
    if (error == ERROR_IN_FILE)
        printf("In file error\n");
    if (error == ERROR_OK)
        printf("Anwser: %d\n", answer);
    if (error == ERROR_NO_DATA_IN_FILE)
        printf("No data in input file\n");
}
