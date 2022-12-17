// 베르트랑 공준  // math  // number theory  // Sieve of Eratosthenes 
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N = 123456 * 2;
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

	int n;
	cin >> n;
	while (n) {
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] != 0) {
				cnt++;
			}
		}
		cout << cnt << "\n";
		cin >> n;
	}

	return 0;
}