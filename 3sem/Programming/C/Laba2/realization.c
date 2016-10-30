#include "realization.h"

//Вычислить значение x[0] + x[0]*x[1] + x[0]*x[1]*x[2] + ... + x[0]*x[1]*x[2] ... x[m],
//где x[i] - элементы массива x из n элементов, m - индекс первого отрицательного элемента
//этого массива либо число n-1, если такого элемента в массиве нет.

int sdelat_labu(FILE *in_file, int *answer)
{
    int errorcode = ERROR_OK;
    int elems_count = get_file_items_count(in_file);
    if (elems_count == 0)
        return ERROR_NO_DATA_IN_FILE;

    int *array = malloc(sizeof(int) * elems_count);
    if (array == NULL)
        return ERROR_MALLOC;

    rewind(in_file);

    errorcode = fill_array(in_file, array, elems_count);
    if (errorcode != ERROR_OK)
        return errorcode;

    int *last_elem = array + elems_count;

    int index = find_first_negative_index(array, last_elem);

    //*answer = calculate(array, index);
    *answer = calculate(array, array + index);

    free(array);

    return ERROR_OK;
}


int calculate(const int *start, const int *finish)
{
    int ans = 0;
    int now = 1;
    const int *pointer = start;
    assert(pointer != NULL);
    while (pointer != finish)
    {
        now *= *pointer;
        pointer++;
        ans += now;
    }
    return ans;
}


int get_file_items_count(FILE *f)
{
    assert(f);
    int tmp;
    int count = 0;
    while ((fscanf(f, "%d", &tmp)) == 1)
    {
        count++;
    }
    return count;
}


int find_first_negative_index(int *start, int *finish)
{
    int ans = 0;
    int *pointer;
    pointer = start;
    while (pointer != finish)
    {
        if (*pointer < 0)
        {
            return ans + 1;
        }
        ans++;
        pointer++;
    }
    return ans;
}

int fill_array(FILE *file, int *array, int count)
{
    int *pointer = array;
    if (!pointer)
        return ERROR_UNDEFINED;
    for (int i = 0; i < count; i++)
    {
        fscanf(file, "%d", pointer);
        pointer++;
    }
    return ERROR_OK;
}
