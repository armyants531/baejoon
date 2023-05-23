#include <bits/stdc++.h> 

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int x, y;
	scanf("%d%d", &x, &y);
	if (N == 1) {
		printf("%d\n", 0);
	}
	else if ((x == 1 || x == N) && (y == 1 || y == N)) {
		printf("%d\n", 2);
	}
	else if (x == 1 || x == N) {
		printf("%d\n", 3);
	}
	else if (y == 1 || y == N) {
		printf("%d\n", 3);
	}
	else {
		printf("%d\n", 4);
	}
}