#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, min, max;
	printf("Enter n, min and max, separated by single space:\n");
	int matches = scanf("%d %d %d", &n, &min, &max);
	if (matches == 3 && n >= 1 && max > min)
	{
		int i, r;

		for (i = 0; i < n; i++) {
			r = rand() % (max + 1 - min) + min;
			printf("%d ", r);
		}
		printf("\n");
	}
	else
	{
		printf("Invalid input.\n");
	}
	
	return 0;
}
