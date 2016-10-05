#include <stdlib.h>
#include <stdio.h>
#include "list.h"


struct list_node* create_node(int num)
{
    struct list_node *node = malloc(sizeof(struct list_node));

    if (node)
    {
        node->num  = num;
        node->next = NULL;
    }

    return node;
}




void add_front(struct list_node *head, struct list_node *node)
{
    assert(head);
    node->next = head;
}


void add_end(struct list_node *head, struct list_node *node)
{
    struct list_node *cur = head;

    assert(head);

    for ( ; cur->next; cur = cur->next)
        ;

    cur->next = node;
}


struct list_node* lookup(struct list_node *head, int num)
{
    for ( ; head; head = head->next)
        if (head->num == num)
            return head;

    return NULL;
}



void print(struct list_node *head)
{
    printf("List:\n");
    for ( ; head; head = head->next)
        printf("%d ", head->num);

    printf("\n");
}


void free_all(struct list_node *head)
{
    struct list_node *next;

    for ( ; head; head = next)
    {
        next = head->next;
        free(head);
    }
}


struct list_node* del_by_value(struct list_node *head, int val)
{
    struct list_node *cur, *prev = NULL;

    for (cur = head; cur; cur = cur->next)
    {
        if (cur->num == val)
        {
            if (prev)
                prev->next = cur->next;
            else
                head = cur->next;

            free(cur);

            return  head;
        }
        prev = cur;
    }

    return NULL;
}
