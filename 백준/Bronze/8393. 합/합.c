#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, t, i;
	t = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		t += i;
	printf("%d", t);
}