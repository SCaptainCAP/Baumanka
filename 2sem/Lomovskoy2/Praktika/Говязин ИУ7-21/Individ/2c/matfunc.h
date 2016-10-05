#include <stdio.h>

#ifndef MATFUNC_H
#define MATFUNC_H

/*!
    Подсчет математического ожидания
    \param[in] f Указатель на входной поток
    \param[in] count Количество данных во входном потоке
    \return Математическое ожидание входной последоватеьности
*/
float matWait(FILE *f, int count);

/*!
    Подсчет дисперсии
    \param[in] f Указатель на входной поток
    \param[in] count Количество данных во входном потоке
    \return Дисперсию входной последоватеьности
*/
float dispersion(FILE *f, int count);

#endif
