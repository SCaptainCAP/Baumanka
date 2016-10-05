#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_OK 0
#define ERROR_BAD_ARGUMENTS -1
#define ERROR_BAD_FILE -2
#define ERROR_IO -3

float matWait(FILE *f, int count);
float dispersion(FILE *f, int count);
int analyzeFile(FILE *f);
/*!
    Главная функция. Служит для исследования входного файла, обработки ошибок и вызова других функций
    \param[in] argc Количество аргументов командной строки
    \param[in] argv Аргументы командной строки. Первый аргумент - имя входного файла.
*/
int main(int argc, char** argv)
{
    FILE *f;
    int count = 0;
    if (argc == 2)
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
        {
            printf("\nI/O error\n");
            return ERROR_IO;
        }
        count = analyzeFile(f);
        if (count != 0)
        {
            printf("Dispersion: %f\n",dispersion(f,count));
            printf("MatWait:    %f\n",matWait(f,count));
            fclose(f);
            return ERROR_OK;
        }
        else
        {
            printf("\nBad file, check it\n");
            fclose(f);
            return ERROR_BAD_FILE;
        }
    }
    else
    {
       printf("\nThere must be 1 argument - the name of the input file\n");
       return ERROR_BAD_ARGUMENTS;
    }
}
