#ifndef _LIST_H_
#define _LIST_H_

#include "error_codes_and_defines.h"

struct list_node
{
    int num;

    struct list_node *next;
};


struct list_node* create_node(int num);

struct list_node* get(struct list_node *head, int index);

void add_front_node(struct list_node *head, struct list_node *node);

int add_front(struct list_node *head, int num);

void add_end_node(struct list_node *head, struct list_node *node);

int add_end(struct list_node *head, int num);

int add_index(struct list_node *head, int num, int index);

int get_count(struct list_node *head);

void fprint_list(struct list_node *head, FILE *f);

void free_all(struct list_node *head);

struct list_node* del_by_value(struct list_node *head, int val);

//TODO: add add


#endif  // #ifndef _LIST_H_
