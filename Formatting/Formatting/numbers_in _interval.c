#include <stdio.h>

int main()
{
	int start, end, p;
	p = 0;
	int matches = scanf("%d %d", &start, &end);
	for (;start <= end; start++)
	{
		if(start % 5 == 0)
		{
			p++;
		}
	}
	printf("%d\n", p);
	return 0;
}