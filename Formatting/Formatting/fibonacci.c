#include <stdio.h>

int main()
{
	int number, first, second, next, i;
	first = 0;
	second = 1;
	int matches = scanf("%d", &number);
	if(matches != 1 || number < 1)
	{
		printf("Wrong input.");
	} else
	{
		for (i = 0; i < number; i++)
		{
			if (i <= 1)
			{
				next = i;
			}
			else
			{
				next = first + second;
				first = second;
				second = next;
			}
			printf("%d ", next);
		}
	}

	return 0;
}
