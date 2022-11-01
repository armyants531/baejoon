#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	if (n >= 90 && n <= 100)
		printf("%c", 'A');
	else if (n >= 80 && n <= 89)
		printf("%c", 'B');
	else if (n >= 70 && n <= 79)
		printf("%c", 'C');
	else if (n >= 60 && n <= 69)
		printf("%c", 'D');
	else
		printf("%c", 'F');
}