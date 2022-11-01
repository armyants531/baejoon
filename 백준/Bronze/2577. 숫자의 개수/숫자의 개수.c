#include <stdio.h>

int main(void) {
	int A, B, C, num;
	int ar[10] = { 0 };
	int rest; //나머지
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);

	num = A * B * C;
	while (num > 0) {
		rest = num % 10;
		num /= 10;
		++ar[rest]; //숫자 세기
	}

	int i;
	for (i = 0; i < 10; i++) {
		printf("%d\n", ar[i]);
	}
}