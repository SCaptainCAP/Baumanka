#include "realization.h"
#include <stdio.h>
#define PREC 0.1

int check_answer(float a, float b)
{
   return (abs(a - b) < PREC);
}

int test_find_average_in_array()
{
    printf("Testing find_average_in_array...\n");

    float array1[] = {1, 2, 6};

    int size1 = 3;
    int error = 0;

    if (!check_answer(find_average_in_array(array1, size1), 3))
        error += 1;

    float array2[] = {2, 8};
    int size2 = 2;

    if (!check_answer(find_average_in_array(array2, size2), 5))
        error += 1;

    float array3[] = {2, 4, 8, 10};
    int size3 = 4;
    if (!check_answer(find_average_in_array(array3, size3), 6))
        error += 1;

    if (error == 0)
        printf("Done!\n\n");
    else
        printf("There are %d errors\n",error);
    return error;
}

int test_fill_new_array()
{
    printf("Testing count_more_than_average...\n");

    float array1[] = {1, 2, 6};
    float array1ans[3] = {0};
    int size1 = 3;
    int average1 = 3;
    int error = 0;

    fill_new_array(array1, size1, array1ans, average1);
    if ((array1ans[0] != 6) && (array1ans[1] != 0) && (array1ans[3] != 0))
        error++;

    float array2[] = {2, 8};
    float array2ans[2] = {0};
    int size2 = 2;
    float average2 = 5;

    fill_new_array(array2, size2, array2ans, average2);
    if ((array1ans[0] != 8) && (array1ans[1] != 0))
        error++;

    float array3[] = {2, 4, 8, 10};
    float array3ans[4] = {0};
    int size3 = 4;
    int average3 = 6;

    fill_new_array(array3, size3, array3ans, average3);
    if ((array1ans[0] != 10) && (array1ans[1] != 0) && (array1ans[2] != 0) && (array1ans[3] != 0))
        error++;

    if (error == 0)
        printf("Done!\n\n");
    else
        printf("There are %d errors\n", error);
    return error;
}

int main()
{
    test_fill_new_array();
    test_find_average_in_array();
}
