#include <stdio.h>

int main()
{
	int n, i;
	double result = 1;
	printf("Enter n:\n");
	int matches = scanf("%d", &n);
	if (matches == 1  && n >= 0 && n < 100)
	{
		int divider = 2; 
		for (i = n + 1; i <= 2*n; i++)
		{
			result = (double)(result*i) / divider;
			divider++;
		}
		printf("%.4lf\n", result);
	}
	else
	{
		printf("Invalid input.");
	}

	return 0;
}
