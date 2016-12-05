#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "error_codes_and_defines.h"

struct list_node
{
    int num;

    struct list_node *next;
};


struct list_node* create_node(int num);
void free_all(struct list_node *head);
int add_after(struct list_node **head, struct list_node* after, int num);
int add_end(struct list_node **head, int num);
void fprint_list(struct list_node *head, FILE *f);



#endif
