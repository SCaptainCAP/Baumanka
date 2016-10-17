#ifndef _LONG_NUMBER_H
#define _LONG_NUMBER_H

#include <string.h>

#define MANTIS_LENGTH 30

#define MAX_EXP 99999
#define MIN_EXP -99999

#define INPUT_INTEGER 1
#define INPUT_REAL 0

#define POSITIVE 1
#define NEGATIVE 0

#define ERROR_OK                        0

#define ERROR_INTERNAL                  1
#define ERROR_EXPONENT_OVERFLOW         2
#define ERROR_INVALID_FORMAT            3
#define ERROR_MANTIS_OVERFLOW           4
#define ERROR_INVALID_FORMAT_INTEGER    5

#define SUB_SECOND_LESS                 11
#define SUB_EQUALS                      12

#define DIVISION_TO_ZERO                21
#define DIVISION_EXPONENT_OVERFLOW      23


typedef struct ln
{
    char mantis[MANTIS_LENGTH + 1];
    int exponent;
    int mantis_sign;

} ln;

static inline int chrtoi(char c){
    return c - '0';
}
static inline char itochr(int i){
    return i + '0';
}

int read_ln(ln* destination, int mode);
int multiply(ln* n, int m);
int print_long_number(const ln* number);
int division(ln *n, ln* m, ln* answer);



int sub_positive(ln* n, ln* m);
#endif
