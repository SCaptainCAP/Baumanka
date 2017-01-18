#include "realization.h"
#include <stdio.h>
#include <string.h>
#define PREC 0.1

int my_strcmp(const char* str1, const char* str2) {
    if (my_strlen(str1) != my_strlen(str2))
        return 0;
    for (int i = 0; i < my_strlen(str1); i++) {
        if (str1[i] != str2[i])
            return 0;
    }
    return 1;
}

int test_replacer()
{
    printf("Testing replacer...\n");

    int error = 0;

    char* tmp = replacer("Kusty", "ty", "my");
    if (!my_strcmp(tmp, "Kusmy")) error++;
    free(tmp);

    tmp = replacer("Kusty", "ty", "");
    if (!my_strcmp(tmp, "Kus")) error++;
    free(tmp);

    tmp = replacer("pripvetp", "p", "R");
    if (!my_strcmp(tmp, "RriRvetR")) error++;
    free(tmp);

    tmp = replacer("aaaa", "aa", "aaa");
    if (!my_strcmp(tmp, "aaaaaa")) error++;
    free(tmp);

    tmp = replacer("aaa", "bbb", "c");
    if (!my_strcmp(tmp, "aaa")) error++;
    free(tmp);

    tmp = replacer("test", "aaa", "my");
    if (!my_strcmp(tmp, "test")) error++;
    free(tmp);

    tmp = replacer("Kustyc", "ty", "my");
    if (!my_strcmp(tmp, "Kusmyc")) error++;
    free(tmp);

    if (error == 0)
        printf("Done!\n\n");
    else
        printf("There are %d errors\n",error);
    return error;
}

int test_my_strlen()
{
    printf("Testing my_strlen...\n");

    int error = 0;

    if (!(my_strlen("") == 0)) error++;
    if (!(my_strlen("abc") == 3)) error++;
    if (!(my_strlen("qwerty") == 6)) error++;

    if (!(my_strlen("") == strlen(""))) error++;
    if (!(my_strlen("abc") == strlen("abc"))) error++;
    if (!(my_strlen("qwertyqwe") == strlen("qwertyqwe"))) error++;

    if (error == 0)
        printf("Done!\n\n");
    else
        printf("There are %d errors\n",error);
    return error;
}

int test_my_strdup()
{
    printf("Testing my_strdup...\n");

    int error = 0;

    char* tmp = my_strdup("abc");
    if (!my_strcmp(tmp, "abc")) error++;
    free(tmp);

    tmp = my_strdup("");
    if (!my_strcmp(tmp, "")) error++;
    free(tmp);

    if (error == 0)
        printf("Done!\n\n");
    else
        printf("There are %d errors\n",error);
    return error;
}

int test_read_line_from_file()
{
    printf("Testing read_line_from_file...\n");

    int error = 0;

    FILE* f = fopen("tests/rlff1.txt", "r");
    char* tmp = read_line_from_file(f);
    if (!my_strcmp(tmp, "abc")) error++;
    free(tmp);

    tmp = read_line_from_file(f);
    if (!my_strcmp(tmp, "def")) error++;
    free(tmp);

    tmp = read_line_from_file(f);
    if (!my_strcmp(tmp, "g")) error++;
    free(tmp);

    tmp = read_line_from_file(f);
    if (tmp != NULL) error++;

    fclose(f);


    f = fopen("tests/rlff2.txt", "r");
    tmp = read_line_from_file(f);
    if (tmp != NULL) error++;

    fclose(f);

    if (error == 0)
        printf("Done!\n\n");
    else
        printf("There are %d errors\n",error);
    return error;
}

int test_my_strspn()
{
    printf("Testing my_strspn...\n");

    int error = 0;

    if (!(my_strspn("", "") == 0)) error++;
    if (!(my_strspn("abc", "abc") == 3)) error++;
    if (!(my_strspn("privet", "pivo") == 1)) error++;
    if (!(my_strspn("pivet", "pivo") == 3)) error++;

    if (error == 0)
        printf("Done!\n\n");
    else
        printf("There are %d errors\n",error);
    return error;
}

int main()
{
    test_replacer();
    test_my_strlen();
    test_my_strdup();
    test_my_strspn();
    test_read_line_from_file();
}
