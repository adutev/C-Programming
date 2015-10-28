#include <stdio.h>

int main() {
	char characters[128];
	int i;
	for (i = 1; i <= 127; i++) {
		characters[i - 1] = i;
	}
	characters[i - 1] = '\0';

	printf("%s", characters);
	

	return 0;
}