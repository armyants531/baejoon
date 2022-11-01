#include <stdio.h>

int ar[1000000];

int main(void) {
	int i;
	int N;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &ar[i]);
	}
	int max;
	
	max = ar[0];

	for (i = 1; i < N; i++) {
		if (max < ar[i])
			max = ar[i];
	}
	
	int min;

	min = ar[0];

	for (i = 1; i < N; i++) {
		if (min > ar[i])
			min = ar[i];
	}

	printf("%d %d\n", min, max);
}