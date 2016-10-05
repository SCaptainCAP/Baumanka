#include "fileanalyzer.h"
#include "matfunc.h"
#include <stdio.h>
FILE *f;

int testMatWait(){
    int nice = 0;
    float ans = 0;

    printf("Testing mat wait...\n");

    f = fopen("matWaitTests/1", "r");
    ans = matWait(f,3);
    if (ans == 2)
        nice += 1;
    fclose(f);

    f = fopen("matWaitTests/2", "r");
    ans = matWait(f,1);
    if (ans == 3)
        nice += 1;
    fclose(f);

    f = fopen("matWaitTests/3", "r");
    ans = matWait(f,5);
    if (ans == 3)
        nice += 1;
    fclose(f);

    printf("Testing mat wait end, %d from 3 passed\n",nice);

    return nice;
}

int testDisp(){
    int nice = 0;
    float ans = 0;

    printf("Testing dispersion...\n");

    f = fopen("dispTests/1", "r");
    ans = dispersion(f,1);
    if (ans == 0)
        nice += 1;
    fclose(f);

    f = fopen("dispTests/2", "r");
    ans = dispersion(f,1);
    if (ans == 0)
        nice += 1;
    fclose(f);

    f = fopen("dispTests/3", "r");
    ans = dispersion(f,1);
    if (ans == 0)
        nice += 1;
    fclose(f);

    printf("Testing dispersion end, %d from 3 passed\n",nice);

    return nice;
}

int testAnalyzer(){
    int nice = 0;
    float ans = 0;

    printf("Testing file analyzer...\n");

    f = fopen("fileAnalyzerTests/1", "r");
    ans = analyzeFile(f);
    if (ans == 3)
        nice += 1;
    fclose(f);

    f = fopen("fileAnalyzerTests/2", "r");
    ans = analyzeFile(f);
    if (ans == 0)
        nice += 1;
    fclose(f);

    f = fopen("fileAnalyzerTests/3", "r");
    ans = analyzeFile(f);
    if (ans == 2)
        nice += 1;
    fclose(f);

    printf("Testing file analyzer end, %d from 3 passed\n",nice);

    return nice;
}

int main(){
    testMatWait();
    testAnalyzer();
    testDisp();
}
