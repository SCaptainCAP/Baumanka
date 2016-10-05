#include <stdio.h>
int main(void)
{
	float inp,max;
	if (scanf("%f",&inp))
		max = inp;
	while (scanf("%f",&inp) == 1)
	{
		if (inp > max)
			max = inp;
	}
	printf("max is %f",max);
}
