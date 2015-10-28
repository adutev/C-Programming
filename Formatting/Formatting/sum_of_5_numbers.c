#include <stdio.h>

int main()
{
	long double a, b, c, d, e;
	int matches = scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
	if(matches != 5)
	{
		printf("Invalid input.");
	} else
	{
		printf("Sum: %.2lf \n", (a + b + c + d + e));
	}

	return 0;
}