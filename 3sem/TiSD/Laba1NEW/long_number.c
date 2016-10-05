#include "long_number.h"

#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

static void remove_zeros(ln* number)
{
    assert(number);

    // remove zeros at the end and increase exponent
    if (number->mantis[0] != '0' && strlen(number->mantis) != 1)
    {
        while (number->mantis[strlen(number->mantis) - 1] == '0') {
            number->mantis[strlen(number->mantis) - 1] = '\0';
        }
    }
}

static int equals(const ln* n, const ln* m)
{
    if (m->mantis_sign != n->mantis_sign)
        return 0;
    if (m->exponent != n->exponent)
        return 0;
    if (strlen(m->mantis) != strlen(n->mantis))
        return 0;
    for (int i = 0; i <= strlen(m->mantis); i++)
    {
        if (chrtoi(m->mantis[i]) != chrtoi(n->mantis[i]))
            return 0;
    }
    return 1;
}

int read_ln(ln* number, int mode)
{
    assert(number);

    int index = 0;
    int exponent_offset = 0;
    int point_entered = 0;
    int digit_entered = 0;
    int exponent_offset_end = 0;

    char input;

    for (int i = 0; i <= MANTIS_LENGTH; i++)
        number->mantis[i] = '\0';

    // skip whitespaces
    while(isspace(input = getchar()));

    number->mantis_sign = POSITIVE;
    number->exponent = 0;

    // check first symbol

    // if it is digit -> to mantis
    if(isdigit(input))
    {
        if (input != '0')
        {
            number->mantis[index] = input;
            index++;
            digit_entered = 1;
            number->exponent = 1;
        }
    }
    // if it is + or - -> set sign
    else if(input == '+' || input == '-')
    {
        if (input == '-')
            number->mantis_sign = NEGATIVE;
    }
    // if it is dot -> it is REAL
    else if(input == '.')
    {
        if(mode == INPUT_INTEGER)
            return ERROR_INVALID_FORMAT;

        point_entered = 1;
    }
    else return ERROR_INVALID_FORMAT;


    // if it is not digit or dot, than break
    while(isdigit(input = getchar()) || input == '.')
    {
        if(input != '.')
        {
            if (digit_entered || input != '0')
            {
                digit_entered = 1;
                if(index >= MANTIS_LENGTH)
                    return ERROR_MANTIS_OVERFLOW;
                number->mantis[index] = input;
                index++;
                if (!point_entered) // before first dot
                    exponent_offset += 1;
            }
            else
                if (point_entered)
                    exponent_offset -= 1;
        }
        else if(mode == INPUT_INTEGER)
        {
            return ERROR_INVALID_FORMAT;
        }
        else if(point_entered == 1) // two points entered
        {
            return ERROR_INVALID_FORMAT;
        }
        else point_entered = 1;
    }

    number->mantis[index] = '\0';

    if(!digit_entered) // there were no digits
        return ERROR_INVALID_FORMAT;

    // handle exponent
    if (input != '\n')
    {
        int exp_minus = 0;
        if (input != ' ')
            return ERROR_INVALID_FORMAT;
        if ((input = getchar()) != 'E')
            return ERROR_INVALID_FORMAT;
        if ((input = getchar()) != ' ')
            return ERROR_INVALID_FORMAT;
        if(isdigit(input = getchar()))
        {
            exponent_offset_end = input - '0';
        }
        // if it is + or - -> set sign
        else if(input == '+' || input == '-')
        {
            if (input == '-')
                exp_minus = 1;
        }
        while ((input = getchar()) != '\n')
        {
            if(isdigit(input))
            {
                exponent_offset_end *= 10;
                exponent_offset_end += chrtoi(input);
            }
            else
                return ERROR_INVALID_FORMAT;
        }
        if (exp_minus)
            exponent_offset_end *= -1;

    }

    number->exponent += exponent_offset_end + exponent_offset;

    remove_zeros(number);

    if(number->exponent > MAX_EXP || number->exponent < MIN_EXP)
        return ERROR_EXPONENT_OVERFLOW;

    return ERROR_OK;
}

int multiply(ln* n, int m)
{
    assert(m >= 0);
    assert(m < 10);
    int tmpmas[MANTIS_LENGTH + 2];
    int i = 0;
    int tmp;
    char c;
    int manlen = (strlen(n->mantis) - 1);
    tmpmas[0] = 0;
    for (i = manlen; i >= 0; i--)
    {
        c = n->mantis[i];
        tmp = chrtoi(c) * m;
        tmpmas[i + 1] = tmp;
    }
    for (i = manlen + 1; i >= 1; i--)
    {
        tmpmas[i - 1] += tmpmas[i] / 10;
        tmpmas[i] %= 10;
    }
    if (tmpmas[0] > 0)
    {
        if (manlen + 1 >= MANTIS_LENGTH)
        {
            for (i = manlen + 1; i >= 1; i--)
            {
                if (tmpmas[i] > 5)
                    tmpmas[i - 1] += 1;
                if (tmpmas[i - 1] != 10)
                    break;
                else
                    tmpmas[i - 1] = 0;
            }
        }
        else
        {
            memmove(n->mantis + 1, n->mantis, manlen + 1);
        }
        n->exponent++;
    }
    else
        memmove(tmpmas, tmpmas + 1, manlen + 1);

    for (i = (strlen(n->mantis) - 1); i >= 0; i--)
    {
        n->mantis[i] = itochr(tmpmas[i]);
    }
    return ERROR_OK;
}

int sub_positive(ln* n, ln* m)
{
    assert(m->mantis_sign == POSITIVE);
    assert(n);
    assert(m);

    if (equals(n,m))
    {
        n->exponent = 0;
        n->mantis_sign = POSITIVE;
        n->mantis[0] = 0;
        n->mantis[1] = '\0';
    }
//    if (m->is_bigger_than(n))
//        n->mantis_sign = NEGATIVE;
    // simplest variant
    char tmp_mantis[MANTIS_LENGTH + 1];
    memcpy(tmp_mantis, m->mantis, MANTIS_LENGTH + 1);
    return ERROR_OK;
}

int print_long_number(const ln* number)
{
    assert(number);

    //int printable_exponent = number->exponent +
    //                       strlen(number->mantis);

    if(number->mantis_sign == NEGATIVE)
        printf("-");

    printf("0.%s", number->mantis);

    //if(printable_exponent != 0)
        //printf(" E %d", printable_exponent);
        printf(" E %d", number->exponent);

    return ERROR_OK;
}

//static void swap_sign(ln* n)
//{
//    if (n->mantis_sign == POSITIVE)
//        n->mantis_sign = NEGATIVE;
//    else
//        n->mantis_sign = POSITIVE;
//}

//static int is_bigger_than(const ln* n, const ln* m)
//{
//    if (m->mantis_sign == POSITIVE && n->mantis_sign == NEGATIVE)
//        return 1;
//    if (m->mantis_sign == NEGATIVE && n->mantis_sign == POSITIVE)
//        return 0;
//    if (m->mantis_sign == POSITIVE)
//    {
//        if (m->exponent > n->exponent)
//            return 1;
//        if (m->exponent < n->exponent)
//            return 0;
//        if (strlen(m->mantis) > strlen(n->mantis))
//            return 1;
//        if (strlen(m->mantis) < strlen(n->mantis))
//            return 0;
//        for (int i = 0; i <= strlen(m->mantis); i++)
//        {
//            if (chrtoi(m->mantis[i]) > chrtoi(n->mantis[i]))
//                return 1;
//        }
//        return 0;
//    }
//    else
//    {
//        if (m->exponent > n->exponent)
//            return 0;
//        if (m->exponent < n->exponent)
//            return 1;
//        if (strlen(m->mantis) > strlen(n->mantis))
//            return 0;
//        if (strlen(m->mantis) < strlen(n->mantis))
//            return 1;
//        for (int i = 0; i <= strlen(m->mantis); i++)
//        {
//            if (chrtoi(n->mantis[i]) > chrtoi(m->mantis[i]))
//                return 1;
//        }
//        return 0;
//    }
//}

