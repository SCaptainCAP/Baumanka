#include <stdio.h>
int main(void)
{
    int max = 0, count = 0;
    int num = 0;
    scanf("%f", &max);
    while (scanf("%d", num) == 1)
    {
        if (num > max)
            max = num;
        else
            if (num = max)
                count++;
    }
    printf("max %d, count %d\n", &max, &count);
    return 0;
}
