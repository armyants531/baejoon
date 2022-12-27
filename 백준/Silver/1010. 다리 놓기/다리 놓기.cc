// 다리 놓기  // math  // 조합론  // dp
// 답: mCn
// nCk + nCk+1 = n+1Ck+1
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> binomial(31, vector<int>(31, 0));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1; i < 31; i++) {
        for (int j = 0; j < 31; j++) {
            if (j == 0 || i == j) {
                binomial[i][j] = 1;
            }
            else {
                binomial[i][j] = binomial[i - 1][j] + binomial[i - 1][j - 1];
            }
        }
    }

    for (int i = 0; i < T; i++) {
        ll N, M;
        cin >> N >> M;
        cout << binomial[M][N] << "\n";
    }
    return 0;
}