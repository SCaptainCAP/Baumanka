#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct list_node
{
    int num;
    struct list_node *next;
    struct list_node *prev;
};


struct list_node* create_node(int n)
{
    struct list_node *p = malloc(sizeof(struct list_node));
    if (p)
    {
        p->next = NULL;
        p->prev = NULL;
        p->num = n;
    }
    return p;
}

struct list_node* add_node(struct list_node *head, struct list_node *elem)
{
    if (head == NULL) {
        head = elem;
        head->next = head;
        head->prev = head;
        return head;
    }
    else {
        elem->next = head->next;
        head->next = elem;
        elem->prev = head;
        elem->next->prev = elem;
    }
    return elem;
}

struct list_node* del_elem(struct list_node *head) {
    if (head->next == head->prev && head->next == head) {
        free(head);
        return NULL;
    }
    head->next->prev = head->prev;
    head->prev->next = head->next;
    struct list_node *tmp = head->next;
    free(head);
    return tmp;
}
void print(struct list_node *head) {
    if (head == NULL) {
        printf("EMPTY LIST!\n");
        return;
    }

    struct list_node *p = head;
    do {
        printf("%d ", p->num);
        p = p->next;
    } while (p != head);
    printf("\n");
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    struct list_node* head = NULL;
    for (int i = 0; i < n; i++)
    {
        head = add_node(head, create_node(i));
    }

    struct list_node* tmp = head;
    while (head->next != head)
    {
        print(head);
        tmp = head;
        for (int j = 0; j < m; j++)
        {
            tmp = tmp->next;
        }
        del_elem(tmp);
    }

    while ((head = del_elem(head)) != NULL);
    return 0;
}