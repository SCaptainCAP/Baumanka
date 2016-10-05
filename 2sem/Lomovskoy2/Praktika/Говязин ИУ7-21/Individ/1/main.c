#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_OK 0
#define ERROR_BAD_DATA -1
#define ERROR_NO_VALID_DATA -2



/*!
    Главная функция. Ищет наибольшее положительное число, следующее за отрицательным
    \param[in] f Указатель на входной поток
    \param[in] ans Указатель на ответ
*/
int process(FILE *f, float *ans)
{
    float inp;
    int lastPlus = 1; //Last number was positive
    int wasOne = 0; //At least one input is nice
    int emptyFile = 1; //File is empty
    while ((fscanf(f, "%f", &inp) == 1)){
        emptyFile = 0;
        if (inp < 0)
        {
            lastPlus = 0;
        }
        if (inp > 0)
        {
            if (!lastPlus)
            {
                if (!wasOne)
                {
                    *ans = inp;
                    wasOne = 1;
                }
                else
                {
                    if (inp > *ans)
                        *ans = inp;
                }
            }
            lastPlus = 1;

        }
        if (inp == 0)
            lastPlus = 1;
    }
    if (emptyFile)
        return ERROR_NO_VALID_DATA; /// file is empty
    if (wasOne)
        return ERROR_OK; /// nice job
    else
        return ERROR_BAD_DATA; /// bad data
}


/*!
    Используется для вызова функции process и обработки ошибок
*/
int main(void)
{

    float ans;
    float error;

    printf("Input line of numbers please. End with ctrl+d\n");

    error = process(stdin,&ans);

    if (error == ERROR_OK)
    {
        printf("\nAnswer is %f\n",ans);
    }
    if (error == ERROR_BAD_DATA)
    {
        printf("\nNo answer for this input\n");
    }
    if (error == ERROR_NO_VALID_DATA)
    {
        printf("\nThere is bo valid data\n");
    }
    return error;
}
