#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void last_digit(int a)
{
	int digit = a % 10;
	
	switch(digit)
	{
		case 1:
			printf("one");
			break;
		case 2:
			printf("two");
			break;
		case 3:
			printf("three");
			break;
		case 4:
			printf("four");
			break;
		case 5:
			printf("five");
			break;
		case 6:
			printf("six");
			break;
		case 7:
			printf("seven");
			break;
		case 8:
			printf("eight");
			break;
		case 9:
			printf("nine");
			break;
		case 0:
			printf("zero");
			break;
	}
}

int main()
{
	int a;
	printf("Enter an integer:");
	scanf("%d", &a);

	last_digit(a);

	return 0;
}

