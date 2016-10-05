#ifndef __REALIZATION_H__
#define __REALIZATION_H__

#include "error_codes_and_defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sdelat_labu(FILE *in_file, int *answer);

/*!
    \brief Returns what we need to do in tasl
    \param f Input file
    \param finish Pointer to the LAST element of array.
    \param start Pointer to the beginning of array
*/
int calculate(int *start, int *finish);

/*!
    \brief Returns amount of integer numbers
    \param f Input file
*/
int get_file_items_count(FILE *f);

/*!
    \brief Finds the index of first negative element in array. If there is no one, returns last index.
    \param finish Pointer to the LAST element of array.
    \param start Pointer to the beginning of array
*/
int find_first_negative_index(int *start, int *finish);

/*!
    \brief Fills the given array with numbers in file (count numbers)
    \param file Input file
    \param array Array to fill
    \param count Amount of data in array
*/
int fill_array(FILE *file, int *array, int count);

#endif
