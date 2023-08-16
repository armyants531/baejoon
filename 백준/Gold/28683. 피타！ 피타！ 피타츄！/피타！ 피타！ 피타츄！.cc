#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int sq = sqrt(N);
	if (sq * sq == N) {
		cout << -1 << "\n";
	}
	else {
		int cnt = 0;
		// a^2 + b^2 = N
		for (int i = 1; i <= sqrt(N / 2); i++) {
			int b = N - i * i;
			int q = sqrt(b);
			if (q * q == b) {
				cnt++;
			}
		}
		// a^2 - b^2 = (a - b)(a + b) = N
		// let s = a-b, l = a+b
		for (int s = 1; s * s <= N; s++) {
			if (N % s) continue;
			int l = N / s;
			if (s % 2 == l % 2) cnt++;
		}
		cout << cnt << "\n";
	}
	
	return 0;
}