#include "realization.h"

int sdelat_labu(FILE *in_file, FILE *out_file)
{
    float read_array[MAX_ARRAY_SIZE] = { 0 };
    float new_array[MAX_ARRAY_SIZE] = { 0 };
    int in_count = 0;
    int errorcode = ERROR_OK;
    float average = 0;
    int c_more_aver = 0;

    //read file to array
    errorcode = read_array_from_file(in_file, read_array, &in_count);
    if (errorcode != ERROR_OK)
        return errorcode;

    //find average
    average = find_average_in_array(read_array, in_count);

    //fill new array with elements that are more than average
    if (fill_new_array(read_array, in_count, new_array, average) != ERROR_OK)
        return ERROR_NO_MORE_AVER;

    //print new array to file
    print_to_file(out_file, new_array, c_more_aver);
    return ERROR_OK;
}

float find_average_in_array(const float array[], int size)
{
    assert(size > 0);
    float answer = 0;
    for (int i = 0; i < size; i++)
    {
        answer += array[i];
    }
    return answer / size;
}

void print_to_file(FILE *out_file, const float *array, int count)
{
    for (int i = 0; i < count; i++)
    {
        fprintf(out_file, "%f\n", array[i]);
    }
}

int count_more_than_average(const float array[], int size, float average)
{
    int answer = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > average)
            answer++;
    }
    return answer;
}

int read_array_from_file(FILE *f, float *arra, int *count)
{
    float tmp;
    *count = 0;
    while ((fscanf(f, "%f", &tmp)) == 1)
    {
        if (*count == MAX_ARRAY_SIZE)
        {
            return ERROR_IN_TOO_LARGE;
        }
        arra[*count] = tmp;
        *count = *count + 1;
    }
    if (*count == 0)
        return ERROR_NO_DATA_IN_FILE;
    return ERROR_OK;
}

int fill_new_array(float *last, int in_count, float *ne, float aver)
{
    int more_than_aver = 0;
    int j = 0;
    for (int i = 0; i < in_count; i++)
    {
        if (last[i] > aver)
        {
            ne[j] = last[i];
            j++;
            more_than_aver += 1;
        }
    }
    if (more_than_aver == 0)
        return ERROR_NO_MORE_AVER;
    else
        return ERROR_OK;
}
