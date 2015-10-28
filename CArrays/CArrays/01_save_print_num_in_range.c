#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	int matches = scanf("%d", &n);
	int numbers[120];
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &numbers[i]);
	}
	return 0;
}