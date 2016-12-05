#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

void add_front_node(struct list_node *head, struct list_node *node)
{
    assert(node);
    if (!head)
    {
        head = node;
    }
    int tmp = head->num;
    head->num = node->num;
    node->num = tmp;
    node->next = head->next;
    head->next = node;
}

int add_front(struct list_node *head, int num)
{
    struct list_node *node = create_node(num);
    if (node == NULL)
        return ERROR_MALLOC;
    add_front_node(head, node);
    return ERROR_OK;
}

void add_index_node(struct list_node *head, struct list_node *node, int index)
{
    if (index < 0 || index > get_count(head))
        return;
    if (index == 0) {
        add_front_node(head, node);
        return;
    }
    if (index == get_count(head)) {
        add_end_node(head, node);
        return;
    }
    node->next = get(head, index)->next;
    get(head, index)->next = node;
}

int add_index(struct list_node *head, int num, int index)
{
    struct list_node *node = create_node(num);
    if (node == NULL)
        return ERROR_MALLOC;
    add_index_node(head, node, index);
    return ERROR_OK;
}

void add_end_node(struct list_node *head, struct list_node *node)
{
    assert(head);
    assert(node);
    get(head, get_count(head) - 1)->next = node;
}

int add_end(struct list_node *head, int num)
{
    struct list_node *node = create_node(num);
    if (node == NULL)
        return ERROR_MALLOC;
    add_end_node(head, node);
    return ERROR_OK;
}

int get_count(struct list_node *head)
{
    assert(head);
    int i = 1;
    while (head->next != NULL)
    {
        head = head->next;
        i++;
    }
    return i;
}

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

struct list_node* get(struct list_node *head, int index)
{
    assert(head);
    assert(index >= 0);
    struct list_node* ans = head;
    for (int i = 0; i < index; i++)
    {
        ans = ans->next;
        if (ans == NULL)
            return NULL;
    }
    return ans;
}

void fprint_list(struct list_node *head, FILE *f)
{
    for ( ; head; head = head->next)
        fprintf(f, "%d ", head->num);

    fprintf(f, "\n");
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
