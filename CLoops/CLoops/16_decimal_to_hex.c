#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main() {
	long decimalNumber, remainder, quotient;
	int i = 1, j, temp;
	char hexadecimalNumber[100];

	printf("Enter a decimal number: \n");
	scanf("%u", &decimalNumber);

	quotient = decimalNumber;

	while (quotient != 0) {
		temp = quotient % 16;

		if (temp < 10)
		{
			temp = temp + 48;
		}
		else
		{
			temp = temp + 55;
		}			

		hexadecimalNumber[i++] = temp;
		quotient = quotient / 16;
	}

	for (j = i - 1;j> 0;j--)
	{
		printf("%c", hexadecimalNumber[j]);
	}	

	return 0;
}

