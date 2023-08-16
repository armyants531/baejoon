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
		for (int i = 1; i <= sqrt(N / 2); i++) {
			int b = N - i * i;
			int q = sqrt(b);
			if (q * q == b) {
				cnt++;
			}
		}
		//cout << cnt << "\n";
		vector<int> f(1000001);
		int c = 1;
		int M = N;
		for (int i = 2; i * i <= M; i++) {
			while (M % i == 0) {
				M /= i;
				f[i]++;
			}	
		}
		if (N % 2 == 0) {
			f[2] -= 2;
		} 
		for (int i = 2; i * i <= N; i++) {
			c *= (f[i] + 1);
		}
		if (M != 1 && N != 2) {
			c *= 2;
		}
		cnt += c / 2;
		cout << cnt << "\n";
	}
	
	return 0;
}