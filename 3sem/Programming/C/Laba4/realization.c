#include "realization.h"
#include <string.h>
#define EOL '\n'
#define DEFAULT_READ_BUFFER 5
#define BIGGER 0
#define EQUALS 1
#define LESS -1

int sdelat_labu(FILE* in, FILE* out, const char* what, const char* to) {
//    fprintf(out, "%s", replacer())
    char *str;
    char *tmp;
    int count = 0;
    while ((str = read_line_from_file(in)) != NULL) {
        count++;
        tmp = replacer(str, what, to);
        if (!tmp) {
            free(str);
            return ERROR_MALLOC;
        }
        fprintf(out, "%s\n", tmp);
        printf("%s\n", tmp);
        free(tmp);
        free(str);
    }
    if (count)
        return ERROR_OK;
    else
        return ERROR_NO_DATA_IN_FILE;
}

int min(int a, int b) {
    return (a > b) ? b : a;
}

char *my_realloc(char *old, int old_size, int new_size)
{
    char *new_str = malloc(new_size * sizeof(char));
    if (new_str) {
        for (int i = 0; i < min(old_size, new_size); i++) {
            new_str[i] = old[i];
        }
    }
    if(old_size != 0)
        free(old);
    return new_str;
}

size_t my_strspn(const char *string1, const char *string2) {
    assert(string1);
    assert(string2);
    size_t str1len = my_strlen(string1);
    size_t str2len = my_strlen(string2);
    short ok;
    for (size_t i = 0; i < str1len; i++) {
        ok = 0;
        for (size_t j = 0; j < str2len; j++) {
            if (string1[i] == string2[j])
                ok = 1;
        }
        if (!ok)
            return i;
    }
    return str1len;
}

char *my_strdup(const char *str) {
    assert(str);
    size_t len = my_strlen(str);
    char *ans = malloc(sizeof(char) * (len + 1));
    if (!ans)
        return NULL;
    for (int i = 0; i <= len; i++) {
        ans[i] = str[i];
    }
    return ans;
}

char* read_line_from_file(FILE* f) {
    assert(f);
    char* ans = NULL;
    char* tmp = NULL;
    char buffer[DEFAULT_READ_BUFFER];
    int mylen = 0, j = 0;
    while(fgets(buffer, DEFAULT_READ_BUFFER, f))
    {
        tmp = realloc(ans, mylen + my_strlen(buffer) + 1);
        if (!tmp)
            return NULL;
        ans = tmp;
        j = mylen;
        while(buffer[j - mylen] != '\0' && buffer[j - mylen] != EOF && buffer[j - mylen] != EOL)
        {
            ans[j] = buffer[j - mylen];
            j++;
        }
        ans[j] = '\0';
        if(buffer[j - mylen] == '\n')
            break;
        mylen = j;
    }
    return ans;
}

char* replacer(char *str, const char* what, const char* to) {
    assert(str);
    assert(what);
    assert(to);
    size_t len = my_strlen(str);
    size_t whatlen = my_strlen(what);
    size_t tolen = my_strlen(to);
    size_t oldlen;
    int diff;
    char *ans = my_strdup(str);
    char *tmp;
    int pos = -1;

    if (whatlen > len || whatlen == 0)
        return ans;

    if (tolen > whatlen)
        diff = BIGGER;
    else if (tolen == whatlen)
        diff = EQUALS;
    else
        diff = LESS;

    for (int i = 0; i <= len - whatlen; i++) {
        if (ans[i] == what[0]) { // maybe it is start
            pos = i; // we can be some kind of naive
            for (int j = 1; j < whatlen; j++) {
                if (ans[i + j] != what[j]) {
                    pos = -1; // our hopes were not justifyed
                    break;
                }
            }
            if (pos == -1)
                continue;
            oldlen = len;
            len = len + tolen - whatlen; // new length of str
            if (len <= 0) {
                free(ans);
                return my_strdup("");
            }

            if (diff == BIGGER) {
                // realloc our string
                tmp = my_realloc(ans, oldlen + 1, len + 1);
                if (!tmp) {
                   return NULL;
                }
                ans = tmp;
            }

            if (diff == BIGGER) {
                for (int j = len; j >= pos + tolen; j--) {
                    ans[j] = ans[j - len + oldlen];
                }
            }
            if (diff == LESS) {
                for (int j = pos + tolen; j <= len; j++) {
                    ans[j] = ans[j - tolen + whatlen];
                }
            }

            for (int j = pos; j < pos + tolen; j++) {
                ans[j] = to[j - pos];
            }

            if (diff == LESS) {
                // realloc our string
                tmp = my_realloc(ans, oldlen + 1, len + 1);
                if (!tmp) {
                   return NULL;
                }
                ans = tmp;
            }

            i = pos + tolen - 1;
        }
    }
    return ans;
}

size_t my_strlen(const char *str) {
    if (str == NULL)
        return 0;
    size_t count = 0;
    while (str && *str != '\0') {
        str++;
        count++;
    }
    return count;
}
