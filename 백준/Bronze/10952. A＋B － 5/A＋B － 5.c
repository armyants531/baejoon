#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b, c;
	while (1)
	{
		scanf("%d %d", &a, &b);
		c = a + b;
		if (a == 0 && b == 0)
			break;
		else
			printf("%d\n", c);
	}
}