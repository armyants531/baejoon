// 골드바흐의 추측  // math  // number theory  // Sieve of Eratosthenes
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N = 10000;
	vector<int> arr(N + 1, 0);
	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}
	int sqr = sqrt(N);
	for (int i = 2; i <= sqr; i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = i * i; j <= N; j += i) {
			arr[j] = 0;
		}
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		for (int a = n / 2; a >= 2; a--) {
			if (arr[a] != 0 && arr[n - a] != 0) {
				cout << a << " " << n - a << "\n";
				break;
			}
		}
	}

	return 0;
}