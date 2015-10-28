#include <stdio.h>

int larger_than_neighbours(int* arr);

int main()
{
	int sequenceOne[] = { 1, 3, 4, 5, 1, 0, 5 };
	int l1 = sizeof(sequenceOne) / sizeof(int);
	int first_array_largest = larger_than_neighbours(sequenceOne, l1);
	printf("%d\n", first_array_largest);

	int sequenceTwo[] = { 1, 2, 3, 4, 5, 6, 6 };
	int l2 = sizeof(sequenceTwo) / sizeof(int);
	int second_array_largest = larger_than_neighbours(sequenceTwo, l2);
	printf("%d\n", second_array_largest);

	int sequenceThree[] = { 1, 1, 1 };
	int l3 = sizeof(sequenceThree) / sizeof(int);
	int third_array_largest = larger_than_neighbours(sequenceThree, l3);
	printf("%d\n", third_array_largest);

	return 0;
}

int larger_than_neighbours(int* arr, int len)
{
	int position = -1;
	int i = 1;
	if(len < 3)
	{
		return -1;
	}
	for (i = 1; i < len - 1; i++)
	{
		if(arr[i-1] < arr[i] && arr[i] > arr[i + 1])
		{
			return i;
		}
	}

	return -1;
}