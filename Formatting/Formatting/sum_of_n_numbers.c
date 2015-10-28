#include <stdio.h>

int main()
{
	int n;
	int hasResult = 0;

	int matches = scanf_s("%d", &n);
	if (matches != 1)
	{
		printf("Invalid input.");
	}
	else
	{
		int i;
		double sum = 0;
		double newNumber = 0;
		for (i = 0; i < n; i++)
		{			
			int matches = scanf("%lf", &newNumber);
			if(matches != 1)
			{
				printf("wrong input. aborting now...\n");
				hasResult = 0;
				break;
			}
			sum += newNumber;
			hasResult = 1;
		}
		if(hasResult)
		{
			printf("sum is: %.1lf\n", sum);
		}
		
	}

	return 0;
}