#include <stdio.h>
#include <stdlib.h>

void reverse_string(char* source, char* destination, int size, int i, int j);
int main()
{
	char* str = "Pipi The Long sock";
	int size = 19;
	char destination[19];
	reverse_string(str, destination, size, 0, 17);
	printf("%s\n", destination);
	return 0;
}

void reverse_string(char* source, char* destination, int size, int i, int j)
{
	if(i == size - 1)
	{
		destination[i] = '\0';
		return;
	}
	destination[j] = source[i];
	reverse_string(source, destination, size, ++i, --j);	 
}