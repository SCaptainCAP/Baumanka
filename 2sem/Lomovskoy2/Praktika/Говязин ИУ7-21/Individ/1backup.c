#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int process(FILE *f){
    float inp;
    float ans;
    int lastPlus = 1; //Last number was positive
    int wasOne = 0; //At least one input is nice
    int emptyFile = 1; //File is empty
    while (fscanf(f, "%f", &inp) == 1){
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
                    ans = inp;
                    wasOne = 1;
                }
                else
                {
                    if (inp > ans)
                        ans = inp;
                }
            }
            lastPlus = 1;

        }
        if (inp == 0)
            lastPlus = 1;
    }
    fclose(f);
    if (emptyFile)
        printf("File is empty\n");

    if (wasOne)
        return ans;
    else
    {
        printf("No answer for this input\n");
        return -1;
    }
}

int main(int argc, char** argv)
{
    FILE *f;
    int ans;
    if (argc != 2)
    {
        printf("Please enter file name as argument\n");
        return -1;
    }
    else
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
        {
            printf("I/O error\n");
            return -1;
        }
        ans = process(f);
        if (ans == -1)
            return -1;
        else
        {
            char* fname;
            fname = (char*) calloc (strlen(argv[1]) + 3,sizeof(char));
            strcpy(fname, argv[1]);
            strcat(fname,"out");
            printf("Please check file %s\n",fname);
            f = fopen(fname, "w");
            fprintf(f,"%d", ans);
            fclose(f);
        }
    }
    return 0;
}
