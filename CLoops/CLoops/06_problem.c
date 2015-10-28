#include <stdio.h>

int calcFactoriel(int n);

int main()
{
	int n, k;
	printf("Enter n and x, separated by space:\n");
	int matches = scanf_s("%d %d", &n, &k);
	if (matches == 2 && k > 1 && n > k && n < 100 )
	{
		printf("%.2fl", (float)calcFactoriel(n) / (float)calcFactoriel(k));
	}
	else
	{
		printf("Invalid input.");
	}

	return 0;
}

int calcFactoriel(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return n * calcFactoriel(n - 1);
}
