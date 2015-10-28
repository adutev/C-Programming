#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX_SIZE 64
#include <math.h>

int main()
{
	long n;
	int i;
	char result[MAX_SIZE];

	printf("Enter a decimal number:\n");
	int matches = scanf("%u", &n);

	if (matches == 1 && n > 0)
	{
		i = log2(n) + 1;
		result[i] = '\0';
		i--;
		while(n > 0)
		{
			if(n % 2 == 1)
			{
				result[i] = '1';
			} else
			{
				result[i] = '0';
			}
			
			n = n / 2;
			i--;
		}
	} else
	{
		printf("Invalid input.");
	}
	printf("%s\n", result);
	return 0;
}
