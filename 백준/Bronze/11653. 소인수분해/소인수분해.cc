// 소인수분해  // number theory  // prime number check
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	while (N > 1) {
		for (int i = 2; i <= N; i++) {
			if (N % i == 0) {
				N /= i;
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}