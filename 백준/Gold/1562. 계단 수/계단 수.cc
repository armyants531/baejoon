// 계단 수  // bitmasking  // dp 
// https://js1jj2sk3.tistory.com/41 참고 
#include <bits/stdc++.h>

using namespace std;
// dp[n][x][2 ^ X(2진수)] = 길이가 n이고 1의 자리수가 x인 계단 수의 개수
// 2진수는 0 ~ 9 까지 사용한 수의 상태를 나타냄
int dp[101][10][1 << 10] = { 0, }; // 1 << 10 == 1024 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans = 0;
	cin >> n;
	int full = (1 << 10) - 1; // 상태비트 최댓값(이진수: 111111111, 십진수: 1023)
	// base case // 1자리 계단수(0 제외)
	for (int i = 1; i <= 9; i++) {
		dp[1][i][1 << i] = 1;
	}
	// DP[n][x][상태비트 | (2 ^ x)] = DP[n-1][x-1][상태비트] + DP[n-1][x+1][상태비트]
	for (int i = 2; i <= n; i++) { // i = 자릿수
		for (int j = 0; j <= 9; j++) { // j = 1의 자리수
			for (int k = 0; k <= full; k++) { // k = 상태비트
				if (j == 0 || j == 9) {
					if (j == 0) {
						dp[i][0][k | 1] += dp[i - 1][1][k];
						dp[i][0][k | 1] %= 1000000000;
					}
					else { // j == 9
						dp[i][9][k | (1 << 9)] += dp[i - 1][8][k];
						dp[i][9][k | (1 << 9)] %= 1000000000;
					}
				}
				else { // 1 <= j <= 8
					dp[i][j][k | (1 << j)] += (dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k]);
					dp[i][j][k | (1 << j)] %= 1000000000;
				}
			}
		}
	}
	for (int i = 0; i <= 9; i++) {
		ans += dp[n][i][full];
		ans %= 1000000000;
	}
	cout << ans << "\n";
	return 0;
}