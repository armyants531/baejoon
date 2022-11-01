#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int y;
	scanf("%d", &y);
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		printf("%d", 1);
	else
		printf("%d", 0);
}