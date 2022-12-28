// 쉬운 계단 수  // DP
// table[n][last] = table[n-1][last-1] + table[n-1][last+1]
#include <bits/stdc++.h>

using namespace std;

// table[len][last]: 길이가 len인 계단 수 중 last로 끝나는 수의 개수 
vector<vector<int>> table(101, vector<int>(10));

void tabulation(int n) {
    // n = 1일 때 예외처리
    table[1][0] = 0;
    for (int i = 1; i <= 9; i++) {
        table[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                table[i][0] = table[i - 1][1];
            }
            else if (j == 9) {
                table[i][9] = table[i - 1][8];
            }
            else { // j: 1 ~ 8
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j + 1]) % 1000000000;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    tabulation(N);
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += table[N][i];
        ans %= 1000000000;
    }
    cout << ans << "\n";

	return 0;
}