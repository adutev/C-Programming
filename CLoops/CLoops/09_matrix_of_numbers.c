#include <stdio.h>

int main()
{
	int n, i, j;
	printf("Enter n:\n");
	int matches = scanf("%d", &n);
	if (matches == 1 && n >= 1 && n <= 20)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++ )
			{
				printf("%4d", i + j + 1);
			}
			printf("\n");
		}
	}
	else
	{
		printf("Invalid input.");
	}

	return 0;
}
