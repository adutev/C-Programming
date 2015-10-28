#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

#define MAX_SIZE 30
int main()
{
	int i, power;
	power = 1;
	unsigned long long result = 0;
	char binary[MAX_SIZE];
	printf("Enter a binary string:\n");
	fgets(binary, MAX_SIZE, stdin);
	if(binary[strlen(binary) - 1] == '\n')
	{
		binary[strlen(binary) - 1] = '\0';
	}

	for (i = strlen(binary) - 1; i >= 0; i-- )
	{
		if(binary[i] == '1')
		{
			result += power;
		}
		power *= 2;
	}
	printf("%llu\n", result);
	return 0;
}
