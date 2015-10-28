#include <stdio.h>
int convertToBinary(int number);

int main()
{
	char print_format[] = "|%-10X|%010d|%10.2f|%-10.3f|\n";
	int a;
	float b, c;
	
	printf("Please entter an integer and two float numbers, separated by single space.\n");
	int matches = scanf("%d %f %f", &a, &b, &c);
	if(matches != 3)
	{
		printf("Invalid input.\n");
	} else if(a < 0 || a > 500)
	{
		printf("Invalid input. A must be 0 <= a <= 500\n");
	} else
	{
		printf(print_format, a, convertToBinary(a), b, c);
	}
	
	return 0;
}

int convertToBinary(int number)
{
	int binary = 0;
	int position = 1;
	while (number / 2 != 0)
	{
		binary += number % 2 * position;
		position *= 10;
		number = number / 2;
	}
	if (number == 1)
	{
		binary += 1 * position;
	}

	return binary;
}