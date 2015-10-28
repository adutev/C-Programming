#include <stdio.h>

int main()
{
	int n;

	int matches = scanf("%d", &n);
	if (matches != 1)
	{
		printf("Invalid input.");
	}
	else
	{
		int i;
		for (i = 1; i <= n; i++)
		{
			printf("%d\n", i);
		}	
	}

	return 0;
}