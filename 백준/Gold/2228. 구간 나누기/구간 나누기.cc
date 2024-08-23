#include<bits/stdc++.h>

using namespace std;

int t[101];
int psum[101];
int dp[101][101];  // dp[i][j]: The maximum value that can be created by selecting j intervals from i numbers 

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> t[i];
	}
	for (int i = 1; i <= N; i++) {
		psum[i] = psum[i-1] + t[i];
	}
	for (int j = 1; j <= M; j++) {
		dp[0][j] = -3276801;
	}
	for (int i = 1; i <= N; i++) {  // init dp[i][1]
		dp[i][1] = dp[i-1][1];
		for (int k = -1; k <= i-2; k++) {  // k = -1 ~ i-2 for j = 1
			dp[i][1] = max(dp[i][1], psum[i] - psum[k+1]);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= M; j++) {  // for j >= 2
			dp[i][j] = dp[i-1][j];
			for (int k = 1; k <= i-2; k++) {  // k = 1 ~ i-2
				dp[i][j] = max(dp[i][j], dp[k][j-1] + psum[i] - psum[k+1]);
			}
		}
	}
	/*
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	cout << dp[N][M] << "\n";
	
	return 0;
}