#include <stdio.h>
#include "array_functions.h"
#include <limits.h>

int arr_min(int* numbers, int len){
	int i;
	int min = INT_MAX;
	for (i = 0; i < len; i++)
	{
		if(numbers[i] < min)
		{
			min = numbers[i];
		}
	}
	return min;
}

int arr_max(int* numbers, int len) {
	int i;
	int max = INT_MIN;
	for (i = 0; i < len; i++)
	{
		if (numbers[i] > max)
		{
			max = numbers[i];
		}
	}
	return max;
}

int arr_clear(int* numbers, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		numbers[i] = 0;
	}	
	return 0;
}

double arr_average(int* numbers, int len) {
	int i;
	double average = 0;
	for (i = 0; i < len; i++)
	{
		average += numbers[i];
	}
	return average/len;
}

long arr_sum(int* numbers, int len) {
	int i;
	long sum = 0;
	for (i = 0; i < len; i++)
	{
		sum += numbers[i];
	}
	return sum;
}

int arr_contains(int* numbers, int len, int element)
{
	int i;
	int contains = 0;
	for (i = 0; i < len; i++)
	{
		if(numbers[i] == element)
		{
			contains = 1;
			return 0;
		}	
	}

	return contains;
}

int* arr_merge(int* array_one, int l1, int* array_two, int l2)
{
	int i, count;
	count = 0;
	int* array_new =  malloc(sizeof(int) * l1 * l2);
	for (i = 0; i < l1; i++)
	{
		array_new[count++] = array_one[i];
	}
	for (i = 0; i < l2; i++)
	{
		array_new[count++] = array_two[i];
	}
	return array_new;
}
