#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int biggest_number(int a, int b)
{
	if(a >= b)
	{
		return a;
	} else
	{
		return b;
	}
}

int main()
{	
	int a, b;
	printf("a:");
	scanf("%d", &a);
	printf("b:");
	scanf("%d", &b);

	printf("%d", biggest_number(a, b));
	return 0;
}

