// 팰린드롬 개수 구하기 (Large)  // dp
// 문자열 내 부분 문자열 팰린드롬 개수 구하기
// s[i] != s[k] 일 때: dp[i][k] = dp[i + 1][k] + dp[i][k - 1] - dp[i + 1][k - 1];
// s[i] == s[k] 일 때: dp[i][k] = dp[i + 1][k] + dp[i][k - 1] - dp[i + 1][k - 1] + (dp[i + 1][k - 1] + 1);
#include<bits/stdc++.h>

using namespace std;

int dp[1001][1001] = { 0, }; // dp[i][j] : [i,j]에서의 답
string s;
int n;

int tabulation() {
	// 길이 1, 2인 연속 팰린드롬 
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
		if (i + 1 < n) {
			if (s[i] == s[i + 1]) {
				dp[i][i + 1] = 3;
			}
			else {
				dp[i][i + 1] = 2;
			}
		}
	}
	for (int j = 2; j < n; j++) {
		for (int i = 0; i + j < n; i++) {
			int k = i + j;
			if (s[i] == s[k]) {
				// 양 끝을 포함한 팰린드롬 생성 가능(dp[i + 1][k - 1] + 1)
				dp[i][k] = (dp[i + 1][k] + dp[i][k - 1] + 1) % 10007;
			}
			else {
				dp[i][k] = (dp[i + 1][k] + dp[i][k - 1] - dp[i + 1][k - 1] + 10007) % 10007; // dp에는 나머지 값 저장하므로 뺄셈 결과가 음수가 될 수 있음
			}
		}
	}

	return dp[0][n - 1];
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	n = s.size();

	cout << tabulation() << "\n";
	
	return 0;
}