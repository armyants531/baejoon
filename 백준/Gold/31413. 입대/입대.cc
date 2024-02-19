// top-down approach
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int dp[1001][1001];
vector<int> s(1000);
int N, M, A, D;

int rec(int i, int j) { // 남은 날짜, 헌혈 가능 수 
	if (i <= 0) return 0;
	if (dp[i][j] != 0) return dp[i][j];
	if (j > 0) { // 헌혈 가능  
		dp[i][j] = max(dp[i][j], rec(i-D, j-1) + A);
	}
	dp[i][j] = max(dp[i][j], rec(i-1, j) + s[N-i]);
	return dp[i][j]; 
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}	
	cin >> A >> D;
	int ans = 100000001;
	int low = 0, high = N;
	while (low <= high) {
		int mid = (low+high)/2; // 헌혈 횟수 
		int p = rec(N, mid);
		if (p >= M) {
			ans = min(ans, mid);
			high = mid-1; 
		}
		else {
			low = mid+1;
		}
	}
	if (ans == 100000001) {
		cout << -1 << "\n";
	}
	else {
		cout << ans << "\n";
	}
	return 0;
}