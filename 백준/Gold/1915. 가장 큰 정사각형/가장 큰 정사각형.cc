// 가장 큰 정사각형  // dp
// dp[i][j] : (i, j)를 오른쪽 아래 꼭짓점으로 가지는 정사각형 한 변의 최대 길이
// (i, j)에 1이 채워져 있으면 dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, m;

vector<vector<int>> arr(1001, vector<int>(1001));
vector<vector<int>> dp(1001, vector<int>(1001));

void tabulation() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 1) {
                dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = s[j - 1] - '0';
        }
    }
 
    tabulation();
    int max_val = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            max_val = max(max_val, dp[i][j]);
        }
    }
    // 최대 넓이 출력
    cout << max_val * max_val << "\n";

    return 0;
}