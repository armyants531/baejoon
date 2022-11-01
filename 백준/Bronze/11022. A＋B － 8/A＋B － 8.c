#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b, c, t, i;
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d %d", &a, &b);
		c = a + b;
		printf("Case #%d: %d + %d = %d\n", i, a, b, c);
	}
}