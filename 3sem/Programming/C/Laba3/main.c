#include <stdio.h>
#include "error_codes_and_defines.h"
#include "realization.h"

void show_error_message(int error);
int main(int argc, char *argv[])
{
    int errorcode = ERROR_OK;
    if (argc != 3)
    {
        errorcode = ERROR_BAD_ARGUMENT_COUNT;
    }
    else
    {
        //open in file
        FILE * in_file = fopen(argv[1], "r");
        if (in_file == 0)
        {
            errorcode = ERROR_IN_FILE;
        }
        else
        {
            //open out file
            FILE * out_file = fopen(argv[2], "w");
            if (out_file == 0)
            {
                errorcode = ERROR_OUT_FILE;
            }
            else
            {
                errorcode = sdelat_labu(in_file, out_file);
                fclose(out_file);
            }
            fclose(in_file);
        }
    }
    show_error_message(errorcode);
    return errorcode;
}
void show_error_message(int error)
{
    if (error == ERROR_BAD_ARGUMENT_COUNT)
        printf("Bad argument count\n");
    if (error == ERROR_IN_FILE)
        printf("In file error\n");
    if (error == ERROR_OUT_FILE)
        printf("Out file error\n");
    if (error == ERROR_NO_MORE_AVER)
        printf("No answer, check input file\n");
    if (error == ERROR_OK)
        printf("Check out file\n");
    if (error == ERROR_IN_TOO_LARGE)
        printf("Too many data in input file\n");
    if (error == ERROR_NO_DATA_IN_FILE)
        printf("No data in input file\n");
}
