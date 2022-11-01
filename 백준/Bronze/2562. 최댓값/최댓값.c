#include <stdio.h>

int main(void) {
	int i;
	int ar[9];
	for (i = 0; i < 9; i++) {
		scanf("%d", &ar[i]);
	}
	int num = 1;
	int max = ar[0];
	for (i = 1; i < 9; i++) {
		if (max < ar[i]) {
			max = ar[i];
			num = i + 1; // num은 몇 번째인지 
		}
	}
	printf("%d\n", max);
	printf("%d\n", num);
}