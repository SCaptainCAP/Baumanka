#include "realization.h"


//Разработайте программу, которая вводит из файла, имя которого определяется
//в командной строке, числа и помещает их в линейный односвязный список так,
//чтобы элементы его составляли возрастающую последовательность. Затем из исходного
//списка сформировать два списка: первый будет содержать четные элементы исходного
//списка, второй - нечетные. Числа из этих списков записать в файл, имена
//которых определяются в командной строке.


int sdelat_labu(FILE *in_file, FILE *out_file_chetn, FILE *out_file_nechetn)
{
    int error = ERROR_OK;
    struct list_node *in_list = NULL;
    error = read_file_fill_list_inc(in_file, &in_list);
    if (error != ERROR_OK) {
        return error;
        free_all(in_list);
    }
    struct list_node *out_list_chetn = NULL;
    struct list_node *out_list_nechetn = NULL;

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
    assert(f);
    int tmp = 0;
    struct list_node *now, *prevnow;
    while ((fscanf(f, "%d", &tmp)) == 1) {
        now = *head;
        // Add to start
        if (!now || now->num >= tmp) {
            add_after(head, NULL, tmp);
            continue;
        }
        // Add to other place
        while (now && (now->num < tmp)) {
            prevnow = now;
            now = now->next;
        }
        add_after(head, prevnow, tmp);
    }
    // There was no data in file
    if (*head == NULL)
        return ERROR_NO_DATA_IN_FILE;
    return ERROR_OK;
}

int fill_out_lists(struct list_node* in_list, struct list_node** out_list_chetn, struct list_node** out_list_nechetn)
{
    int num = 0;
    while (in_list != NULL)
    {
        num = in_list->num;
        if (num % 2 == 0) {
            if (add_end(out_list_chetn, num) != ERROR_OK)
                    return ERROR_MALLOC;
        }
        else {
            if (add_end(out_list_nechetn, num) != ERROR_OK)
                    return ERROR_MALLOC;
        }
        in_list = in_list->next;
    }
    return ERROR_OK;
}


