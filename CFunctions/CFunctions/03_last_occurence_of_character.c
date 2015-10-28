#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_LINE 1000

int last_occurence(char *str, char ch)
{
	int i, last;
	last = -1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == ch)
		{
			last = i;
		}
	}
	return last;
}

int main()
{
	int c, i;
	char ch;
	i = 0;
	char str[MAX_LINE];
	printf("Enter a string:");
	
	while((c = getchar())!=EOF && c != '\n')
	{
		str[i++] = c;
	}
	str[i] = '\0';

	printf("Enter a character:");
	scanf("%c", &ch);

	printf("%d\n",last_occurence(str, ch));

	return 0;
}

