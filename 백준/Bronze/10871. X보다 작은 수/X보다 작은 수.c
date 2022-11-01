#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, x, i, a;

	scanf("%d %d", &n, &x);

	for (i = 1; i <=n; i++) {
		scanf("%d", &a);
		if (x > a)
			printf("%d ", a);
		else
			continue;
	}
}