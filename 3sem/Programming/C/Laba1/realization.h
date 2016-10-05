#ifndef __REALIZATION_H__
#define __REALIZATION_H__

#include "error_codes_and_defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sdelat_labu(FILE *in_file, FILE *out_file);
float find_average_in_array(const float array[], int size);
int read_array_from_file(FILE *f, float *arra, int *count);
int fill_new_array(float *last, int in_count, float *ne, float aver);
void print_to_file(FILE *out_file, const float *array, int count);

#endif
