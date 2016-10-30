#include "realization.h"
#include "list.h"

int read_file_fill_list_inc(FILE *f, struct list_node **head);
int fill_out_lists(struct list_node* in_list, struct list_node** out_list_chetn, struct list_node** out_list_nechetn);

int sdelat_labu(FILE *in_file, FILE *out_file_chetn, FILE *out_file_nechetn)
{
    int error = ERROR_OK;
    struct list_node *in_list;
    error = read_file_fill_list_inc(in_file, &in_list);
    if (error != ERROR_OK) {
        return error;
        free_all(in_list);
    }
    struct list_node *out_list_chetn;
    struct list_node *out_list_nechetn;

    error = fill_out_lists(in_list, &out_list_chetn, &out_list_nechetn);

    if (error != ERROR_OK) {
        free_all(in_list);
        free_all(out_list_chetn);
        free_all(out_list_nechetn);
        return error;
    }
    else {
        fprint_list(out_list_chetn, out_file_chetn);
        fprint_list(out_list_nechetn, out_file_nechetn);
        free_all(in_list);
        free_all(out_list_chetn);
        free_all(out_list_nechetn);
    }



    return ERROR_OK;
}

int read_file_fill_list_inc(FILE *f, struct list_node **head)
{
    int tmp = 0;
    int none = 1;
    int l = 0;
    int r = 0;
    int mid = 0;
    while ((fscanf(f, "%d", &tmp)) == 1) {
        if (none) {
            *head = create_node(tmp);
        }
        else {
            if (tmp <= get(*head, 0)->num){
                if (add_front(*head, tmp) != ERROR_OK)
                    return ERROR_MALLOC;
            }
            else if (tmp >= get(*head, get_count(*head) - 1)->num){
                if (add_end(*head, tmp) != ERROR_OK)
                    return ERROR_MALLOC;
            }
            else
            {
                l = 0;
                r = get_count(*head) - 1;
                while (l < r - 1) {
                    mid = (l + r) / 2;
                    if (get(*head, mid)->num >= tmp)
                        r = mid;
                    else if (get(*head, mid)->num <= tmp)
                        l = mid;
                }
                if (add_index(*head, tmp, l) != ERROR_OK)
                    return ERROR_MALLOC;
            }
        }
        none = 0;
    }
    if (none == 1)
        return ERROR_NO_DATA_IN_FILE;
    return ERROR_OK;
}

int fill_out_lists(struct list_node* in_list, struct list_node** out_list_chetn, struct list_node** out_list_nechetn)
{
    int none_chetn = 1;
    int none_nechetn = 1;
    int num = 0;
    for (int i = 0; i < get_count(in_list); i++)
    {
        num = get(in_list, i)->num;
        if (num % 2 == 0) {
            if (none_chetn) {
                *out_list_chetn = create_node(num);
            }
            else {
                if (add_end(*out_list_chetn, num) != ERROR_OK)
                        return ERROR_MALLOC;
            }
            none_chetn = 0;
        }
        else {
            if (none_nechetn) {
                *out_list_nechetn = create_node(num);
            }
            else {
                if (add_end(*out_list_nechetn, num) != ERROR_OK)
                        return ERROR_MALLOC;
            }
            none_nechetn = 0;
        }
    }
    return ERROR_OK;
}


