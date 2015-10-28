#include <stdio.h>

int main() {
	int a, b;
	a = 5;
	b = 10;
	int tmp = a;
	printf("Before:\na = %d\nb = %d\n", a, b);
	a = b;
	b = tmp;
	printf("After:\na = %d\nb = %d\n", a, b);
	return 0;
}