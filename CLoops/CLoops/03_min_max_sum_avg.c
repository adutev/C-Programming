#include <stdio.h>
#include <limits.h>

#define MAX_NUMBERS 100

void getNumbers(int n);
void printResults();
int numbers[MAX_NUMBERS];
float avg, sum;
float min = (float)INT_MAX;
float max = (float)INT_MIN;

int main()
{
	int n;
	
	int matches = scanf("%d", &n);
	if (matches == 1 && n >= 1)
	{
		getNumbers(n);
		printResults();
	}
	else
	{
		printf("Invalid input.");
	}
}

void getNumbers(int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		int matches = scanf("%d", &numbers[i]);
		if(matches == 1)
		{
			j = numbers[i];
			if(j <= min)
			{
				min = j;
			}
			if(j >= max )
			{
				max = j;
			}
			sum += j;
		} else
		{
			printf("Wrong input.\n");
			break;

		}
	}
	avg = sum / n;

}

void printResults()
{
	printf("Min: %.2f\n", min);
	printf("Max: %.2f\n", max);
	printf("Sum: %.2f\n", sum);
	printf("Avg: %.2f\n", avg);
}