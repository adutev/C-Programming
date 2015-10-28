#include <stdio.h>

int calcFactoriel(int n);
int calcDivider(int n, int x);

int main()
{
	int n, x, i;
	double sum = 1;
	printf("Enter n and x, separated by space:\n");
	int matches = scanf("%d %d", &n, &x);
	if (matches == 2 && n >= 0)
	{
		for (i = 1; i <= n; i++)
		{
			sum += ((float)calcFactoriel(i) / (float)calcDivider(i, x));
		}
		printf("sum:  %.5lf\n", sum);
	}
	else
	{
		printf("Invalid input.");
	}
	
	return 0;
}

int calcFactoriel(int n)
{
	if(n == 0)
	{
		return 1;
	}
	return n * calcFactoriel(n - 1);
}

int calcDivider(int pow, int x)
{
	int j, result;
	result = 1;
	for (j = 0; j < pow;j++)
	{
		result *= x;
	}
	return result;
}