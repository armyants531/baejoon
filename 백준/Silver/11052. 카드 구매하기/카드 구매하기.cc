#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int p = 10007;

int dp[1001][1001];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i-1][j];
			for (int k = 1; i*k <= j; k++) { // v[i]가치의 팩을 k개 구입 
				dp[i][j] = max(dp[i][j], dp[i-1][j-i*k] + v[i]*k);
			}
		}	
	}
	/*
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	cout << dp[N][N] << "\n";
	
	return 0;
}