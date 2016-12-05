#ifndef __REALIZATION_H__
#define __REALIZATION_H__

#include "error_codes_and_defines.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sdelat_labu(FILE *in_file, FILE *out_file_chetn, FILE *out_file_nechetn);
int read_file_fill_list_inc(FILE *f, struct list_node **head);
int fill_out_lists(struct list_node* in_list, struct list_node** out_list_chetn, struct list_node** out_list_nechetn);
#endif
