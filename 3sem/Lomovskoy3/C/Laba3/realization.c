#include "realization.h"

//Вычислить значение x[0] + x[0]*x[1] + x[0]*x[1]*x[2] + ... + x[0]*x[1]*x[2] ... x[m],
//где x[i] - элементы массива x из n элементов, m - индекс первого отрицательного элемента
//этого массива либо число n-1, если такого элемента в массиве нет.


int sdelat_labu(FILE *in_file, int *answer)
{

    return ERROR_OK;
}

int read_array_from_file(FILE *f, float *arra, int *count)
{
    int tmp = NULL;
    int none = 1;
    while ((fscanf(f, "%d", &tmp)) == 1)
    {
        none = 0;

    }
    if (none == 0)
        return ERROR_NO_DATA_IN_FILE;
    return ERROR_OK;
}


