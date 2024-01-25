// dp[i][j] = iÀÚ¸®¼ö·Î ¸¸µé ¼ö ÀÖ´Â ¼ö Áß K·Î ³ª´« ³ª¸ÓÁö°¡ jÀÎ ¼öÀÇ °³¼ö
// i-1ÀÚ¸® ¼ö¿¡¼­ iÀÚ¸® ¼ö·Î È®Àå! 
// dp[i][(pre * 10 + a[k]) % K] += dp[i-1][pre % K]  // k´Â ÀÎµ¦½º  
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
int p = 1000000007;

vector<vector<int>> dp(101, vector<int>(1001));

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		dp[1][a[i] % K]++;
	}
	if (a[0] == 0) {
		dp[1][0]--; // 0À¸·Î ½ÃÀÛÇÒ ¼ö ¾øÀ½ 
	}
	for (int i = 2; i <= M; i++) {
		for (int j = 0; j < K; j++) { // j´Â K·Î ³ª´« ³ª¸ÓÁö  
			if (dp[i-1][j] == 0) continue; // noting to add
			for (int k = 0; k < N; k++) {
				int r = (j * 10 + a[k]) % K; 
				dp[i][r] += dp[i-1][j];
				dp[i][r] %= p;
			}
		}
	}
	/*
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < K; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	
	cout << dp[M][0] << "\n";
	
	return 0;
}