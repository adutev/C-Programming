#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 30
int main()
{
	int n; 
	int numbers[MAX_SIZE];
	printf("Enter n:\n");
	int matches = scanf("%d", &n);
	if (matches == 1 && n >= 1)
	{
		int i, r, s, tmp;

		for (i = 0; i < n; i++) {
			numbers[i] = i+1;
		}
		for (i = 0; i < 2*n;i++)
		{
			r = rand() % n;
			s = rand() % n;
			tmp = numbers[r];
			numbers[r] = numbers[s];
			numbers[s] = tmp;
			
		}
		for (i = 0; i < n; i++) {
			printf("%d ", numbers[i]);
		}
	}
	else
	{
		printf("Invalid input.\n");
	}

	return 0;
}
