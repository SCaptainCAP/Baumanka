#ifndef __REALIZATION_H__
#define __REALIZATION_H__

#include "error_codes_and_defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

size_t my_strspn(const char *string1, const char *string2);
size_t my_strlen(const char *str);
char *my_strdup(const char *str);
char *replacer(char *str, const char* what, const char* to);
char* read_line_from_file(FILE* f);
int sdelat_labu(FILE* in, FILE* out, const char* what, const char* to);
char* read_line_from_file(FILE* f);

#endif
