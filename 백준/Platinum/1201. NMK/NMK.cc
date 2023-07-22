#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	if (N < M + K - 1 || N > M * K) {
		cout << -1 << "\n";
	}
	else {
		if (K == 1) {
			for (int i = 1; i <= N; i++) {
				cout << i << " ";
			}
			cout << "\n";
		}
		else {
			//vector<vector<int>> arr(K);
			int q = (N - M) / (K - 1);
			int r = (N - M) % (K - 1);
			// size M: 1
			for (int i = N - M + 1; i <= N; i++) {
				cout << i << " ";
			}
			// size q+1: r
			for (int i = 1; i <= r; i++) {
				for (int j = N - M + 1 - i * (q + 1); j <= N - M - (i - 1) * (q + 1); j++) {
					cout << j << " ";
				}
			}
			// size q: K-1-r
			for (int i = 1; i <= K-1-r; i++) {
				for (int j = N - M + 1 - r * (q + 1) - i * q; j <= N - M - r * (q + 1) - (i - 1) * q; j++) {
					cout << j << " ";
				}
			}	
		}
	}
	
	return 0;
}