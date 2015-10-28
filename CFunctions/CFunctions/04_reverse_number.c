#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

double reverse_number(char *doubleString, int *error);

int main()
{
	int error = 0;	double reversed = reverse_number("0.12", &error);	if(error)
	{
		printf("Invalid format\n");
	} else
	{
		printf("%.3f\n", reversed);
	}

	return 0;
}

double reverse_number(char *doubleString, int *error)
{
	int i;
	double result = 0;
	double power = 1;
	int correctFloatPoint = 0;
	int length = strlen(doubleString);
	int hasFloatPoint = 0;

	for (i = 0; i < length; i++)
	{
		char ch = doubleString[i];
		if (ch >= '0' && ch <= '9')
		{
			if (!hasFloatPoint)
			{
				result += (ch - '0') * power;
				power *= 10;
				correctFloatPoint++;
			}
			else
			{
				result += (ch - '0') * power;
				power *= 10;
			}
		}
		else if (ch == '.' && !hasFloatPoint)
		{
			hasFloatPoint = 1;
		}
		else
		{
			error = 1;
			return 0;
		}
	}
	if(hasFloatPoint)
	{
		result = result * pow(0.1, correctFloatPoint);
	}
	
	return result;
}
