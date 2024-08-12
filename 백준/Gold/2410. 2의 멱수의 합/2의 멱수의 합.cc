#include <bits/stdc++.h>
#define int long long 

using namespace std;

vector<int> dp(1000000);  // dp[N]: N 이하의 2의 거듭제곱을 사용하여 N을 만드는 경우의 수 

int p = 1000000000;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i <= N; i++) {
		dp[i] = 1;
	}
	int twos = 2;
	while (N >= twos) {
		for (int i = 1; i <= N; i++) { 
			if (i >= twos) { 
				dp[i] = (dp[i] + dp[i - twos]) % p;
			}
		}
		twos *= 2;
	}
	cout << dp[N] << "\n";
	
	return 0;
}