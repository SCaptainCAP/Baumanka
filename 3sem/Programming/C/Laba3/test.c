#include "realization.h"
#include <stdio.h>

int test_calculate()
{
    printf("Testing calculate...\n");
    int error = 0;

    int *array1 = malloc(sizeof(int) * 4);
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = -1;
    array1[3] = 5;

    int index1 = 2;

    if (calculate(array1,index1) != 3)
        error += 1;

    free (array1);


    int *array2 = malloc(sizeof(int) * 5);
    array2[0] = 1;
    array2[1] = 2;
    array2[2] = 3;
    array2[3] = -1;
    array2[4] = 5;

    int index2 = 3;

    if (calculate(array2,index2) != 9)
        error += 1;

    free (array2);


    if (error == 0)
        printf("Done!\n\n");
    else
        printf("There are %d errors\n",error);
    return error;
}

int test_find_first_negative_index()
{
    printf("Testing calculate...\n");
    int error = 0;

    int *array1 = malloc(sizeof(int) * 4);
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = -1;
    array1[3] = 5;

    int *array1_end = array1 + 4;


    if (find_first_negative_index(array1,array1_end) != 3)
        error += 1;

    free (array1);


    int *array2 = malloc(sizeof(int) * 5);
    array2[0] = 1;
    array2[1] = 2;
    array2[2] = 1;
    array2[3] = -5;
    array2[4] = 6;

    int *array2_end = array2 + 5;

    if (find_first_negative_index(array2,array2_end) != 4)
        error += 1;

    free (array2);


    if (error == 0)
        printf("Done!\n\n");
    else
        printf("There are %d errors\n",error);
    return error;
}

int main()
{
    test_calculate();
    test_find_first_negative_index();
}
