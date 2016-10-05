#include <stdio.h>
#ifndef FILEANALYZER_H
#define FILEANALYZER_H

/*!
    Анализатор файла
    \param[in] f Указатель на входной поток
    \return Количество валидных данных во входом потоке
*/
int analyzeFile(FILE *f);

#endif // FILEANALYZER_H
