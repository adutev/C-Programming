#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

#define MAX_SIZE 50
int main()
{
	int i;
	unsigned long long power = 1;
	unsigned long long result = 0ull;
	char hexadecimal[MAX_SIZE];
	printf("Enter a hecxadecimal string:\n");
	fgets(hexadecimal, MAX_SIZE, stdin);
	if (hexadecimal[strlen(hexadecimal) - 1] == '\n')
	{
		hexadecimal[strlen(hexadecimal) - 1] = '\0';
	}

	for (i = strlen(hexadecimal) - 1; i >= 0; i--)
	{
		int hex = hexadecimal[i];
		int decimalNumber = 0;
		switch(hex)
		{
		case '1':
			decimalNumber = 1;
			break;
		case '2':
			decimalNumber = 2;
			break;
		case '3':
			decimalNumber = 3;
			break;
		case '4':
			decimalNumber = 4;
			break;
		case '5':
			decimalNumber = 5;
			break;
		case '6':
			decimalNumber = 6;
			break;
		case '7':
			decimalNumber = 7;
			break;
		case '8':
			decimalNumber = 8;
			break;
		case '9':
			decimalNumber = 9;
			break;
		case 'A':
			decimalNumber = 10;
			break;
		case 'B':
			decimalNumber = 11;
			break;
		case 'C':
			decimalNumber = 12;
			break;
		case 'D':
			decimalNumber = 13;
			break;
		case 'E':
			decimalNumber = 14;
			break;
		case 'F':
			decimalNumber = 15;
			break;
		default:
			decimalNumber = 0;
			break;
		}
		
		result = result + (power*decimalNumber);
		power = power * 16;
	}
	printf("%llu\n", result);
	return 0;
}
