#include <stdio.h>
#include "error_codes_and_defines.h"
#include "realization.h"


void handle(int error_status);
int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        handle(ERROR_BAD_ARGUMENT_COUNT);
    }

    FILE * in_file = fopen(argv[1], "r");
    if (in_file == 0)
        handle(ERROR_IN_FILE);

    FILE * out_file = fopen(argv[2], "w");
    if (out_file == 0)
    {
        fclose(in_file);
        handle(ERROR_OUT_FILE);
    }

    int errorcode = sdelat_labu(in_file, out_file, argv[3], argv[4]);

    fclose(in_file);
    fclose(out_file);

    handle(errorcode);

    printf("Please check out files\n");
    return 0;
}
void handle(int error_status)
{
    switch (error_status) {
        case ERROR_OK:
            return;
        case ERROR_BAD_ARGUMENT_COUNT:
            printf("Bad argument count\n");
            break;
        case ERROR_IN_FILE:
            printf("In file error\n");
            break;
        case ERROR_OUT_FILE:
            printf("Out file error\n");
            break;
        case ERROR_MALLOC:
            printf("Memory allocation error\n");
            break;
        case ERROR_NO_DATA_IN_FILE:
            printf("No data in input file\n");
            break;
        default:
            printf("Unknown error\n");
            break;
        }
    exit(EXIT_FAILURE);
}
