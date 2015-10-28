#include <stdio.h>

int main() {
	int i;
	 double a[] = { 5.3, 5.00000001, 5.00000005, -0.0000007, -4.999999, 4.999999 };
	 double b[] = { 6.01, 5.00000003, 5.00000001, 0.00000007, -4.999998, 4.999998 };
	 double eps = 0.000001;
	printf("  Number a | Number b | Equal\n");
	for (i = 0; i < 6; i++) {

		 double tmp;
		 double numberA = a[i];
		 double numberB = b[i];
		printf("%10.8f | %.8f| ", numberA, numberB);
		if(numberA > numberB) {
			tmp = numberA;
			numberA = numberB;
			numberB = tmp;
		}
		
		if((numberB - numberA) > eps) {
			printf("false\n");
		}
		else {
			printf("true\n");
		}
	}
	return 0;
}
