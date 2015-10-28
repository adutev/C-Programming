#include <stdio.h>

int main() {
	unsigned short ush = 52130;
	unsigned long long ull = 8942492113;
	char ch = -115;
	int i = 4825932;
	unsigned char uch = 97;
	short sh = -10000;
	long long ll = -35982859328592389;
	
	printf("52130 is %d\n", ush);
	printf("8942492113 is %llu\n", ull);
	printf("-115 is %d\n", ch);
	printf("4825932 is %d\n", i);
	printf("97 is %d\n", uch);
	printf("-10000 is %d\n", sh);
	printf("-35982859328592389 is %lld\n", ll);
}