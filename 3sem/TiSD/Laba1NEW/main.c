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
    case ERROR_INVALID_FORMAT_INTEGER:
        printf("Divider must be integer\n");
        break;
    case ERROR_EXPONENT_OVERFLOW:
        printf("There is exponent overflow. Please enter valid number\n");
        break;
    case ERROR_MANTIS_OVERFLOW:
        printf("There is mantis overflow. Please enter valid number\n");
        break;
    case ERROR_DIVISION_EXPONENT_OVERFLOW:
        printf("Cannot divide. There is exponent overflow\n");
        break;
    case ERROR_DIVISION_TO_ZERO:
        printf("Cannot divide to zero\n");
        break;
    default:
        printf("Unknown error\n");
        break;
    }

    exit(EXIT_FAILURE);
}


int main()
{
    ln first, second, ans;
    printf("FORMAT:\n");
    printf("REAL: [+/-]m.n[ E [+/-]k], where m.n is mantis and k - exponent\n");
    printf("INT : [+/-]m[ E [+/-]k], where m is mantis and k - exponent\n");
    printf("PLEASE INPUT ZERO AS 0\n");

    printf("Please enter real number (divident):\n");

    printf("1    6    11   16   21   26 30\n");
    printf("|    |    |    |    |    |   |\n");

    handle_error(read_ln(&first, INPUT_REAL));

    printf("\nPlease enter integer number (divider):\n\n");

    printf("1    6    11   16   21   26 30\n");
    printf("|    |    |    |    |    |   |\n");

    handle_error(read_ln(&second, INPUT_INTEGER));

    handle_error(division(&first, &second, &ans));

    printf("\nEverything is OK. Your answer is:\n");
    print_long_number(&ans);
    printf("\n");
    return 0;
}

