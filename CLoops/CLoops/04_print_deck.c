#include <stdio.h>

void printDeck();
int main()
{
	printDeck();
	return 0;
}

void printDeck()
{
	int cards[] = {'2', '3', '4' , '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	char suits[] = { 'S', 'H','D', 'S' };
	int i, j;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%c%c ", cards[i], suits[j]);
		}
		printf("\n");
	}
}