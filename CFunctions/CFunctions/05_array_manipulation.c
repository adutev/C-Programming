#include <stdio.h>
#include "array_functions.h"
#include <corecrt_malloc.h>

int main()
{
	int numbers[] = { 12, 2, 23, 41, 5, 6, 7, 8, 1 , 4};
	int length = sizeof(numbers) / sizeof(int);

	int mina = arr_min(numbers, length);
	printf("Min is: %d\n", mina);

	int max = arr_max(numbers, length);
	printf("Max is: %d\n", max);
	
	double average = arr_average(numbers, length);
	printf("Average is: %0.4lf\n", average);
	
	long sum = arr_sum(numbers, length);
	printf("Sum is: %u\n", sum);
	
	int element = 431;
	int contains = arr_contains(numbers, length, element);
	if(contains == 1)
	{
		printf("The array contains: %d\n", element);
	} else
	{
		printf("The array does not contain: %d\n", element);
	}

	int *ptr = arr_merge(numbers, length, numbers, length);
	printf("%d == %d %d == %d \n", ptr[0], ptr[10], ptr[1], ptr[11]);
	free(ptr);

	arr_clear(numbers, length);
	printf("%d %d\n", numbers[0], numbers[1]);

	return 0;
}