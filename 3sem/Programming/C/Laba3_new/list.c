#include "list.h"

int add_end(struct list_node **head, int num)
{
    struct list_node *node = create_node(num);
    if (node == NULL)
        return ERROR_MALLOC;
    if (!(*head))
        *head = node;
    else {
        struct list_node *tmp = *head;
        while (tmp->next) tmp = tmp->next;
        tmp->next = node;
    }
    return ERROR_OK;
}

int add_after(struct list_node **head, struct list_node* after, int num)
{
    struct list_node *node = create_node(num);
    if (node == NULL)
        return ERROR_MALLOC;
    if (!after) {
        node->next = *head;
        *head = node;
    }
    else {
        node->next = after->next;
        after->next = node;
    }
    return ERROR_OK;
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
