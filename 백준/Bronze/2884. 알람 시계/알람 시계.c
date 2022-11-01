#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int H, M, h, m;
	scanf("%d %d", &H, &M);
	if (M >= 45) {
		h = H;
		m = M - 45;
		printf("%d %d", h, m);
	}
	else if (M < 45 && H >= 1) {
		h = H - 1;
		m = M + 60 - 45;
		printf("%d %d", h, m);
	}
	else if (M < 45 && H == 0) {
		h = 23;
		m = M + 60 - 45;
		printf("%d %d", h, m);
	}
		
}