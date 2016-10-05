#include <stdio.h>
#include <stdlib.h>

#include "long_number.h"

static void handle_error(int error_status)
{
    switch (error_status) {
    case ERROR_OK:
        return;
    case ERROR_INVALID_FORMAT:
        printf("Number must be in valid format\n");
        break;
    case ERROR_EXPONENT_OVERFLOW:
        printf("There is exponent overflow. Please enter valid number\n");
        break;
    case ERROR_MANTIS_OVERFLOW:
        printf("There is mantis overflow. Please enter valid number\n");
        break;
    }

    exit(EXIT_FAILURE);
}


int main()
{
    ln first, second;

    printf("Enter real and integer numbers consecutively:\n");

    handle_error(read_ln(&first, INPUT_REAL));
    printf("Anus\n");
    handle_error(read_ln(&second, INPUT_REAL));
    print_long_number(&first);
    printf("\n");
    sub_positive(&first,&second);
    printf("\n");
    print_long_number(&first);
    printf("\n");
    //handle_error(read_ln(&second, integer));

    return 0;
}

