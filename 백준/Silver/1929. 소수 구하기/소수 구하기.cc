// 소수 구하기  // math  // number theory  // Sieve of Eratosthenes
#include <bits/stdc++.h>

using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	vector<int> arr(N + 1, 0);
	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}

	int sqr = sqrt(N);
	for (int i = 2; i <= sqr; i++) {
		if (arr[i] == 0) {
			continue;
		}
		// i * 2 ~ i * (i - 1)은 이미 처리됨 
		for (int j = i * i; j <= N; j += i) {
			arr[j] = 0;
		}
	}
	for (int i = M; i <= N; i++) {
		if (arr[i] != 0) {
			cout << arr[i] << "\n";
		}
	}

	return 0;
}