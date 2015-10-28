#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50


int main()
{
	int odd_product, even_product, product, isOdd;
	isOdd = 1;
	odd_product = 1;
	even_product = 1;
	char numbers[MAX_SIZE];
	fgets(numbers, MAX_SIZE, stdin);
	int length = strlen(numbers);
	if (numbers[length - 1] == '\n')
	{
		numbers[length - 1] = '\0';
	}
	char *token = strtok(numbers, " ");
	while (token != NULL)
	{
		int num = atoi(token);
		if (isOdd)
		{
			odd_product = odd_product * num;
		}
		else
		{
			even_product = even_product * num;
		}
		token = strtok(NULL, " ");
		isOdd = !isOdd;
	}
	if (odd_product == even_product)
	{
		printf("yes\nproduct=%d\n", even_product);
	}
	else
	{
		printf("no\nodd_product = %d\neven_product = %d\n", odd_product, even_product);
	}
	return 0;
}
