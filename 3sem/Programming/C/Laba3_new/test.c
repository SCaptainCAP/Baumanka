#include "realization.h"
#include "list.h"
#include <stdio.h>

int test_read_file_fill_list_inc()
{
    printf("Testing read_file_fill_list_inc...\n");
    int error = 0;

    FILE* f1 = fopen("tests/module/input1.txt", "r");
    struct list_node* l1 = NULL;

    read_file_fill_list_inc(f1, &l1);
    if (!(l1->num == 1) || !(l1->next->num == 2) ||
            !(l1->next->next->num == 3) ||
            !(l1->next->next->next->num == 4) ||
            !(l1->next->next->next->next->num == 5))
        error++;
    free_all(l1);
    fclose(f1);


    FILE* f2 = fopen("tests/module/input2.txt", "r");
    struct list_node* l2 = NULL;

    read_file_fill_list_inc(f2, &l2);
    if (!(l2->num == 1) || !(l2->next->num == 2) ||
            !(l2->next->next->num == 3) ||
            !(l2->next->next->next->num == 4) ||
            !(l2->next->next->next->next->num == 5))
        error++;
    free_all(l2);
    fclose(f2);


    f2 = fopen("tests/module/input3.txt", "r");
    l2 = NULL;
    read_file_fill_list_inc(f2, &l2);
    if (!(l2->num == 1) || !(l2->next->num == 2) ||
            !(l2->next->next->num == 3) ||
            !(l2->next->next->next->num == 4) ||
            !(l2->next->next->next->next->num == 5))
        error++;
    free_all(l2);
    fclose(f2);

    f2 = fopen("tests/module/input4.txt", "r");
    l2 = NULL;
    read_file_fill_list_inc(f2, &l2);
    if (!(l2->num == 1) || !(l2->next->num == 5) ||
            !(l2->next->next->num == 5) ||
            !(l2->next->next->next->num == 5) ||
            !(l2->next->next->next->next->num == 6))
        error++;
    free_all(l2);
    fclose(f2);

    f2 = fopen("tests/module/input5.txt", "r");
    l2 = NULL;
    read_file_fill_list_inc(f2, &l2);
    if (!(l2->num == 1) || !(l2->next->num == 2))
        error++;
    free_all(l2);
    fclose(f2);

    f2 = fopen("tests/module/input6.txt", "r");
    l2 = NULL;
    read_file_fill_list_inc(f2, &l2);
    if (!(l2->num == 1) || !(l2->next->num == 2))
        error++;
    free_all(l2);
    fclose(f2);

    f2 = fopen("tests/module/input7.txt", "r");
    l2 = NULL;
    read_file_fill_list_inc(f2, &l2);
    if (!(l2->num == 1) && !l2->next)
        error++;
    free_all(l2);
    fclose(f2);

    if (error == 0)
        printf("Done!\n\n");
    else
        printf("There are %d errors\n",error);
    return error;
}

int test_fill_out_lists()
{
    printf("Testing fill_out_lists...\n");
    int error = 0;

    struct list_node* l1 = NULL;
    struct list_node* ac1 = NULL;
    struct list_node* an1 = NULL;
    add_end(&l1, 1);
    add_end(&l1, 2);
    add_end(&l1, 3);
    add_end(&l1, 4);
    fill_out_lists(l1, &ac1, &an1);
    if (!(ac1->num == 2) || !(ac1->next->num == 4) ||
            !(an1->num == 1) || !(an1->next->num == 3))
        error++;
    free_all(l1);
    free_all(ac1);
    free_all(an1);

    struct list_node* l2 = NULL;
    struct list_node* ac2 = NULL;
    struct list_node* an2 = NULL;
    add_end(&l2, 1);
    add_end(&l2, 2);
    add_end(&l2, 2);
    add_end(&l2, 5);
    fill_out_lists(l2, &ac2, &an2);
    if (!(ac2->num == 2) || !(ac2->next->num == 2) ||
            !(an2->num == 1) || !(an2->next->num == 5))
        error++;
    free_all(l2);
    free_all(ac2);
    free_all(an2);


    struct list_node* l3 = NULL;
    struct list_node* ac3 = NULL;
    struct list_node* an3 = NULL;
    add_end(&l3, 1);
    add_end(&l3, 3);
    add_end(&l3, 3);
    add_end(&l3, 5);
    fill_out_lists(l3, &ac3, &an3);
    if (!(an3->num == 1) || !(an3->next->num == 3) ||
            !(an3->next->next->num == 3) || !(an3->next->next->next->num == 5) || !(ac3 == NULL))
        error++;
    free_all(l3);
    free_all(ac3);
    free_all(an3);


    struct list_node* l4 = NULL;
    struct list_node* ac4 = NULL;
    struct list_node* an4 = NULL;
    add_end(&l4, 2);
    add_end(&l4, 4);
    add_end(&l4, 4);
    add_end(&l4, 6);
    fill_out_lists(l4, &ac4, &an4);
    if (!(ac4->num == 2) || !(ac4->next->num == 4) ||
            !(ac4->next->next->num == 4) || !(ac4->next->next->next->num == 6) || !(an4 == NULL))
        error++;
    free_all(l4);
    free_all(ac4);
    free_all(an4);

    if (error == 0)
        printf("Done!\n\n");
    else
        printf("There are %d errors\n",error);
    return error;
}

int test_add_end()
{
    int error = 0;
    printf("Testing add_end...\n");

    struct list_node* l1 = NULL;
    add_end(&l1, 1);
    add_end(&l1, 2);
    add_end(&l1, 3);

    if (!(l1->num == 1) || !(l1->next->num == 2) || !(l1->next->next->num == 3))
        error++;

    free_all(l1);

    struct list_node* l2 = NULL;
    add_end(&l2, 0);
    add_end(&l2, 2);
    add_end(&l2, 1);

    if (!(l2->num == 0) || !(l2->next->num == 2) || !(l2->next->next->num == 1))
        error++;

    free_all(l2);

    if (error == 0)
        printf("Done!\n\n");
    else
        printf("There are %d errors\n",error);
    return error;
}

int main()
{
    test_read_file_fill_list_inc();
    test_fill_out_lists();
    test_add_end();
}
