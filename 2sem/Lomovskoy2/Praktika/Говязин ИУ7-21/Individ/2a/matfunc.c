#include <stdio.h>

//#define NDEBUG
#include <assert.h>

/*!
    Подсчет математического ожидания
    \param[in] f Указатель на входной поток
    \param[in] count Количество данных во входном потоке
    \return Математическое ожидание входной последоватеьности
*/
float matWait(FILE *f, int count){
    assert(count != 0);
    rewind(f);
    float inp;
    float ans = 0;
    while ((fscanf(f, "%f", &inp) == 1)){
        ans += inp;
    }
    rewind(f);
    return ans/count;
}

/*!
    Подсчет дисперсии
    \param[in] f Указатель на входной поток
    \param[in] count Количество данных во входном потоке
    \return Дисперсию входной последоватеьности
*/
float dispersion(FILE *f, int count){
    assert(count != 0);
    rewind(f);
    float mw = matWait(f,count);
    float inp;
    float ans = 0;
    while ((fscanf(f, "%f", &inp) == 1)){
        ans += (inp - mw) * (inp - mw);
    }
    rewind(f);
    return ans/count;
}
