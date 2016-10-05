#ifndef _LIST_H_
#define _LIST_H_


struct list_node
{
    int num;

    struct list_node *next;
};


struct list_node* create_node(int num);

struct list_node* add_front(struct list_node *head, struct list_node *node);

struct list_node* add_end(struct list_node *head, struct list_node *node);

struct list_node* lookup(struct list_node *head, int num);

void print(struct list_node *head);

void free_all(struct list_node *head);

struct list_node* del_by_value(struct list_node *head, int val);


#endif  // #ifndef _LIST_H_
