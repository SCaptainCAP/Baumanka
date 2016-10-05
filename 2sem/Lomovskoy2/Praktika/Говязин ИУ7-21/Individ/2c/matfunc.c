#include <stdio.h>
//#define NDEBUG
#include <assert.h>
#include "matfunc.h"

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
