// 피사노 주기  // number theory
#include <bits/stdc++.h>

using namespace std;

int pisano_T(int M) {
	int a = 1;
	int b = 1;
	int T = 0;
	while (true) {
		int temp = (a + b) % M;
		a = b;
		b = temp;
		T++;
		if (a == 1 && b == 1) {
			break;
		}
	}
	return T;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int P;
	cin >> P;
	int N, M;
	for (int i = 0; i < P; i++) {
		cin >> N >> M;
		cout << N << " " << pisano_T(M) << "\n";
	}

	return 0;
}