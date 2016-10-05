#include <stdio.h>
#include "fileanalyzer.h"

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
