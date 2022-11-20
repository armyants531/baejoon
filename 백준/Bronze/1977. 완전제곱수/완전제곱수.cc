// 완전제곱수  // math
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long M, N, sum = 0;
	cin >> M >> N;
	long long a = ceil(sqrt(M));
	long long b = floor(sqrt(N));
	for (long long i = a; i <= b; i++) {
		sum += i * i;
	}
	if (sum == 0) {
		cout << -1 << "\n";
	}
	else {
		cout << sum << "\n" << a * a << "\n";
	}

	return 0;
}