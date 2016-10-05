#include <stdio.h>


/*!
    Анализатор файла
    \param[in] f Указатель на входной поток
    \return Количество валидных данных во входом потоке
*/
int analyzeFile(FILE *f){
    int nice = 0;
    float inp;
    rewind(f);
    while ((fscanf(f, "%f", &inp) == 1)){
        nice += 1;
    }
    rewind(f);
    return nice;
}
