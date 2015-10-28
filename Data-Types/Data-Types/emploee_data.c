#include <stdio.h>

int main() {
	char firstName[] = "Amanda";
	char lastName[] = "Jonson";
	char age = 27;
	char gender = 'f';
	unsigned long long personalID = 8306112507;
	int employeeNumber = 27563571;
	printf("First name: %s\nLast Name: %s\n", firstName, lastName);
	printf("Age: %d\nGender: %c\n", age, gender);
	printf("Personal ID: %llu\n", personalID);
	printf("Unique Employee number: %d\n", employeeNumber);
	return 0;
}
