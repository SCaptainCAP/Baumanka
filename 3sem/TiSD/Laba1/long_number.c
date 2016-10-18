#include "long_number.h"

#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
static void set_ln_zero(ln* n)
{
    n->mantis_sign = POSITIVE;
    n->exponent = 0;
    n->mantis[0] = '0';
    for (int i = 1; i <= MANTIS_LENGTH + 1; i++)
    {
        n->mantis[i] = '\0';
    }
}

static void clone(ln* from, ln* to)
{
    to->exponent = from->exponent;
    to->mantis_sign = from->mantis_sign;
    for (int i = 0; i <= MANTIS_LENGTH; i++)
    {
        to->mantis[i] = from->mantis[i];
    }
}

static void remove_back_zeros(ln* number)
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

static void remove_back_zeros_inc_exp(ln* number)
{
    assert(number);

    // remove zeros at the end and increase exponent
    if (number->mantis[0] != '0' && strlen(number->mantis) != 1)
    {
        while (number->mantis[strlen(number->mantis) - 1] == '0') {
            number->mantis[strlen(number->mantis) - 1] = '\0';
            number->exponent++;
        }
    }
}

static int is_bigger_than(const ln* n, const ln* m)
{
    if (m->mantis_sign == POSITIVE && n->mantis_sign == NEGATIVE)
        return 0;
    if (m->mantis_sign == NEGATIVE && n->mantis_sign == POSITIVE)
        return 1;
    if (m->mantis_sign == POSITIVE)
    {
        //int razn = strlen(m->mantis) - strlen(n->mantis);
        if (m->exponent > n->exponent)
            return 0;
        if (m->exponent < n->exponent)
            return 1;
        for (int i = 0; i <= strlen(n->mantis); i++)
        {
            if (n->mantis[i] == '\0')
                return 0;
            if (m->mantis[i] == '\0')
                return 1;
            if (chrtoi(m->mantis[i]) > chrtoi(n->mantis[i]))
                return 0;
            if (chrtoi(m->mantis[i]) < chrtoi(n->mantis[i]))
                return 1;
        }
        return 0;
    }
    else
    {
        if (m->exponent > n->exponent)
            return 0;
        if (m->exponent < n->exponent)
            return 1;
        if (strlen(m->mantis) > strlen(n->mantis))
            return 0;
        if (strlen(m->mantis) < strlen(n->mantis))
            return 1;
        for (int i = 0; i <= strlen(m->mantis); i++)
        {
            if (chrtoi(n->mantis[i]) > chrtoi(m->mantis[i]))
                return 1;
        }
        return 0;
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
    int zeroFlag = 0;

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
        else
        {
            zeroFlag = 1;
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
            return ERROR_INVALID_FORMAT_INTEGER;

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
            return ERROR_INVALID_FORMAT_INTEGER;
        }
        else if(point_entered == 1) // two points entered
        {
            return ERROR_INVALID_FORMAT;
        }
        else point_entered = 1;
    }

    number->mantis[index] = '\0';

    if(!digit_entered) // there were no digits
    {
        if (zeroFlag)
        {
            number->mantis[0] = '0';
            number->exponent = 0;
            return ERROR_OK;
        }
        else
            return ERROR_INVALID_FORMAT;
    }

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
        else if (input == '\n')
            return ERROR_INVALID_FORMAT;
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

    if(exponent_offset_end > MAX_EXP || exponent_offset_end < MIN_EXP)
        return ERROR_EXPONENT_OVERFLOW;

    number->exponent += exponent_offset_end + exponent_offset;

    remove_back_zeros(number);

    return ERROR_OK;
}

int multiply(ln* n, int m)
{
    assert(m >= 0);
    assert(m <= 10);
    if (m == 0)
    {
        set_ln_zero(n);
        return ERROR_OK;
    }
    if (m == 1)
        return ERROR_OK;
    if (m == 10)
    {
        n->exponent++;
        return ERROR_OK;
    }
    int tmpmas[MANTIS_LENGTH + 1];
    int i = 0;
    int tmp;
    char c;
    int manlen = strlen(n->mantis);
    tmpmas[0] = 0;
    for (i = manlen - 1; i >= 0; i--)
    {
        c = n->mantis[i];
        tmp = chrtoi(c) * m;
        tmpmas[i + 1] = tmp;
    }
    for (i = manlen; i >= 1; i--)
    {
        tmpmas[i - 1] += tmpmas[i] / 10;
        tmpmas[i] %= 10;
    }
    if (tmpmas[0] > 0)
    {
        if (manlen >= MANTIS_LENGTH)
        {
            for (i = manlen; i >= 1; i--)
            {
                if (tmpmas[i] >= 5)
                    tmpmas[i - 1] += 1;
                if (tmpmas[i - 1] != 10)
                    break;
                else
                    tmpmas[i - 1] = 0;
            }
        }
        else
        {
            memmove(n->mantis + 1, n->mantis, manlen);
        }
        n->exponent++;
        if (n->exponent > MAX_EXP)
            return ERROR_EXPONENT_OVERFLOW;
    }
    else
    {
        for (int i = 0; i < MANTIS_LENGTH; i++)
            tmpmas[i] = tmpmas[i + 1];
    }
    for (i = (strlen(n->mantis) - 1); i >= 0; i--)
    {
        n->mantis[i] = itochr(tmpmas[i]);
    }
    remove_back_zeros(n);
    return ERROR_OK;
}

int sub_positive(ln* n, ln* m)
{
    assert(m->mantis_sign == POSITIVE);
    assert(n);
    assert(m);
    int j = 0;

    if (m->mantis[0] == '0' && m->mantis[1] == '\0')
        return ERROR_OK;

    if (equals(n,m))
    {
        set_ln_zero(n);
        return SUB_EQUALS;
    }
    if (is_bigger_than(m,n))
    {
        return SUB_SECOND_LESS;
    }
    int exp_razn = n->exponent - m->exponent;

    // fill tmp_mantis_n with n mantis and a lot of back zeros
    int tmp_mantis_n[MANTIS_LENGTH];
    for (int i = 0; i < MANTIS_LENGTH; i++)
    {
        if (n->mantis[i] == '\0')
            tmp_mantis_n[i] = 0;
        else
            tmp_mantis_n[i] = chrtoi(n->mantis[i]);
    }


    // fill tmp_mantis_m with m mantis and zeros at the beginning
    int tmp_mantis_m[MANTIS_LENGTH];
    for (int i = 0; i < MANTIS_LENGTH; i++)
        tmp_mantis_m[i] = 0;
    for (int i = exp_razn; i < MANTIS_LENGTH; i++)
    {
        if (m->mantis[i - (exp_razn)] != '\0')
            tmp_mantis_m[i] = chrtoi(m->mantis[i - (exp_razn)]);
        else
            tmp_mantis_m[i] = 0;
    }
    //DEBUG
//    for (int i = 0; i < MANTIS_LENGTH; i++)
//        printf("%d ", tmp_mantis_n[i]);
//    printf("\n");
//    for (int i = 0; i < MANTIS_LENGTH; i++)
//        printf("%d ", tmp_mantis_m[i]);
//    printf("\n");
    //DEBUG

    // SUB THEM!!!
    for (int i = MANTIS_LENGTH - 1; i >= 0; i--)
    {
        if (tmp_mantis_m[i] != 0)
        {
            if (tmp_mantis_n[i] >= tmp_mantis_m[i])
                tmp_mantis_n[i] -= tmp_mantis_m[i];
            else
            {
                for (j = i - 1; tmp_mantis_n[j] == 0; j--) ;
                tmp_mantis_n[j] -= 1;
                for (int k = j + 1; k != i; k++)
                {
                    tmp_mantis_n[k] = 9;
                }
                tmp_mantis_n[i] += 10;
                tmp_mantis_n[i] -= tmp_mantis_m[i];
            }
        }
    }

    for (int i = 0; i <= MANTIS_LENGTH; i++)
    {
        n->mantis[i] = '\0';
    }
    int tmp = 0;
    while (tmp_mantis_n[tmp] == 0) {
        tmp++;
    }
    for (int i = tmp; i < MANTIS_LENGTH; i++)
    {
        n->mantis[i - tmp] = itochr(tmp_mantis_n[i]);
    }
    int i = MANTIS_LENGTH;
    while (((n->mantis[i] == '0') || (n->mantis[i] == '\0')) && i >= 0) {
        n->mantis[i] = '\0';
        i--;
    }
    n->exponent -= tmp;

    //DEBUG
//    printf("COUNTER\n");
//    for (int i = 0; i < MANTIS_LENGTH; i++)
//        printf("%d ", tmp_mantis_n[i]);
//    printf("\n");
//    for (int i = 0; i < MANTIS_LENGTH; i++)
//        printf("%d ", tmp_mantis_m[i]);
//    printf("\n");
    //DEBUG
    return ERROR_OK;
}

int division(ln *n, ln* m, ln* answer)
{
    ln tmp;
    ln tmp_m;
    set_ln_zero(&tmp);
    set_ln_zero(answer);
    answer->mantis[0] = '\0';
    int num = 0;
    int ans_man_len = 0;
    int tmp_exp = 0;
    int symbol_count = 0;


    if (m->mantis[0] == '0')
        return ERROR_DIVISION_TO_ZERO;
    if (n->mantis[0] == '0')
    {
        answer->mantis[0] = '0';
        return ERROR_OK;
    }
    if (n->mantis_sign == m->mantis_sign)
        answer->mantis_sign = POSITIVE;
    else
        answer->mantis_sign = NEGATIVE;

    n->mantis_sign = POSITIVE;
    m->mantis_sign = POSITIVE;

    //n->exponent -= m->exponent;
    //m->exponent = 0;
    //answer->exponent = n->exponent + 1;
    answer->exponent = n->exponent- m->exponent + 1;
    n->exponent = 0;
    m->exponent = 0;

    if (answer->exponent > MAX_EXP || answer->exponent < MIN_EXP)
        return ERROR_DIVISION_EXPONENT_OVERFLOW;

    if (equals(n,m))
    {
        answer->mantis[0] = '1';
        return ERROR_OK;
    }

    if (is_bigger_than(m, n))
        answer->exponent -= 1;

    if (answer->exponent > MAX_EXP || answer->exponent < MIN_EXP)
        return ERROR_DIVISION_EXPONENT_OVERFLOW;

    m->exponent = strlen(m->mantis);
    n->exponent = strlen(n->mantis);
    while (is_bigger_than(m, n))
    {
        n->exponent++;
    }
    while ((strlen(answer->mantis) != MANTIS_LENGTH) && (n->mantis[0] != '0'))
    {
        if (is_bigger_than(m, n))
        {
            n->exponent++;
        }
        while (is_bigger_than(m, n))
        {
            n->exponent++;
            if (ans_man_len < MANTIS_LENGTH)
            {
                answer->mantis[ans_man_len] = itochr(0);
                ans_man_len++;
            }
//            else
//            {
//                answer->exponent++;
//                if (answer->exponent > MAX_EXP)
//                    return ERROR_DIVISION_EXPONENT_OVERFLOW;
//            }
        }
        while (is_bigger_than(n, m) || equals(n, m)) { // one division loop
            clone(m, &tmp_m);
            while(is_bigger_than(n, &tmp_m))
            {
                tmp_m.exponent++;
            }
            tmp_m.exponent--;
            num = 1;
            clone(&tmp_m, &tmp);
            multiply(&tmp, num);
            while ((is_bigger_than(n, &tmp) || equals(n, &tmp)) && num <= 9)
            {
                num++;
                clone(&tmp_m, &tmp);
                multiply(&tmp, num);
            }
            num--;
            clone(&tmp_m, &tmp);
            multiply(&tmp, num);
            //tmp_exp = n->exponent;
            tmp_exp = n->exponent;

            //!!!!!!!!!!!!!!!!!!!!!!!!!
            sub_positive(n, &tmp);
            //!!!!!!!!!!!!!!!!!!!!!!!!!

            if (ans_man_len < MANTIS_LENGTH)
            {
                answer->mantis[ans_man_len] = itochr(num);
                ans_man_len++;
            }
//            else
//            {
//                answer->exponent++;
//                if (answer->exponent > MAX_EXP)
//                    return ERROR_DIVISION_EXPONENT_OVERFLOW;
//            }

            //if (is_bigger_than(n, m))
            {
                symbol_count = strlen(tmp.mantis) - (tmp_exp - n->exponent) + 1 + (tmp_exp - tmp.exponent);
                while(strlen(m->mantis) > symbol_count)
                {
                    if (ans_man_len < MANTIS_LENGTH)
                    {
                        answer->mantis[ans_man_len] = itochr(0);
                        ans_man_len++;
                    }
//                    else
//                    {
//                        answer->exponent++;
//                        if (answer->exponent > MAX_EXP)
//                            return ERROR_DIVISION_EXPONENT_OVERFLOW;
//                    }
                    symbol_count++;
                }
            }
        }
        remove_back_zeros_inc_exp(n);
    }
    remove_back_zeros(answer);
    if (strlen(answer->mantis) == MANTIS_LENGTH)
    {
        for (int i = MANTIS_LENGTH + 1; i >= 1; i--)
        {
            if (answer->mantis[i] != '\0')
            {
                if (answer->mantis[i] >= '5')
                    answer->mantis[i] += 1;
                if (answer->mantis[i] <= '9') // symbol after 9
                    break;
                else
                {
                    answer->mantis[i] = '0';
                    answer->mantis[i - 1] += 1;
                }
            }
        }
        if (answer->mantis[0] == '9' + 1)
        {
            answer->mantis[0] = '1';
            for (int i = 1; i < MANTIS_LENGTH + 1; i++)
                answer->mantis[i] = '\0';
            answer->exponent++;

            if (answer->exponent > MAX_EXP)
                return ERROR_DIVISION_EXPONENT_OVERFLOW;
        }
    }
    remove_back_zeros(answer);
    if (answer->exponent > MAX_EXP)
        return ERROR_DIVISION_EXPONENT_OVERFLOW;
    return ERROR_OK;
}

int print_long_number(const ln* number)
{
    assert(number);
    const char* caps = "^    ^    ^    ^    ^    ^   ^";
    const char* posi = "1    6    11   16   21   26 30";
    if(number->mantis_sign == NEGATIVE)
        printf("-");

    printf("0.%s", number->mantis);
        printf(" E %d", number->exponent);

    printf("\n  ");
    for (int i = 0; i < strlen(number->mantis); i++)
        printf("%c", caps[i]);
    printf("\n  ");
    for (int i = 0; i < strlen(number->mantis); i++)
        printf("%c", posi[i]);
    printf("\n");

    return ERROR_OK;
}
