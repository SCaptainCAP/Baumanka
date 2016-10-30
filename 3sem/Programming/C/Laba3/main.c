#include <stdio.h>
#include "error_codes_and_defines.h"
#include "realization.h"

void handle(int error_status);
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        handle(ERROR_BAD_ARGUMENT_COUNT);
    }

    FILE * in_file = fopen(argv[1], "r");
    if (in_file == 0)
        handle(ERROR_IN_FILE);

    FILE * out_file_chetn = fopen(argv[2], "w");
    if (out_file_chetn == 0)
    {
        fclose(in_file);
        handle(ERROR_OUT_FILE);
    }

    FILE * out_file_nechetn = fopen(argv[3], "w");
    if (out_file_nechetn == 0)
    {
        fclose(in_file);
        fclose(out_file_chetn);
        handle(ERROR_OUT_FILE);
    }

    int errorcode = sdelat_labu(in_file, out_file_chetn, out_file_nechetn);

    fclose(in_file);
    fclose(out_file_chetn);
    fclose(out_file_nechetn);

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
        default:
            printf("Unknown error\n");
            break;
        }
    exit(EXIT_FAILURE);
}
