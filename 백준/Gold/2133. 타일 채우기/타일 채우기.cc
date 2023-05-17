// Tri Tiling  // dp
// If n is odd dp[n] = 0
// If n is even dp[n] = 4 * dp[n - 2] - dp[n - 4] 
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> dp(31);

ll memo(int n) {
    if (dp[n] != 0) {
        return dp[n];
    }
    return dp[n] = 4 * memo(n - 2) - memo(n - 4);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    dp[0] = 1;
    dp[2] = 3;
    if (n % 2 == 1) {
        cout << 0 << "\n";
    }
    else {
        cout << memo(n) << "\n";
    }

    return 0;
}