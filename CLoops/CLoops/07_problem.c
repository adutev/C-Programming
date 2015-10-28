#include <stdio.h>

unsigned long long calcFactoriel(int n);

int main()
{
	int n, k, i;
	unsigned long long result = 1;
	printf("Enter n and x, separated by space:\n");
	int matches = scanf("%d %d", &n, &k);
	if (matches == 2 && k > 1 && n > k && n < 100)
	{
		int divider = 1; // (n-k)! is 1, 2, 3... for each iteration
		for (i = k + 1; i <= n; i++)
		{
			result = (result*i) / divider;
			divider++;
		}
		printf("%llu\n", result);
	}
	else
	{
		printf("Invalid input.");
	}

	return 0;
}
