#include <stdio.h>

void pritntSequence(int n);

int main()
{
	int n;
	int matches = scanf("%d", &n);
	if(matches == 1 && n >=1 )
	{
		pritntSequence(n);
	} else
	{
		printf("Invalid input.");
	}
}

void pritntSequence(int n)
{
	int i;
	for (i = 1; i < n; i++)
	{
		printf("%d ", i);
	}
}