#include <stdio.h>

int main() {
	long double f1 = 34.567839023L;
	float f2 = 12.345F;
	long double f3 = 8923.1234857L;
	float f4 = 3456.091F;

	printf("34.567839023 is %0.9lf\n", f1);
	printf(" 12.345 is %.3f\n", f2);
	printf(" 8923.1234857 is %.7lf\n", f3);
	printf("3456.091 is %0.1f\n", f4);
} 