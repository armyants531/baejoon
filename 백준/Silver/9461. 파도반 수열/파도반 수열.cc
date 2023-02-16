// Padovan Sequence  // dp
// dp[n] = dp[n - 5] + dp[n - 1] (n >= 6)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> dp;

ll memo(ll N) {
  if (dp[N] != 0) {
    return dp[N];
  }
  return dp[N] = memo(N - 5) + memo(N - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  dp.resize(101, 0);
  dp[1] = dp[2] = dp[3] = 1;
  dp[4] = dp[5] = 2;
  int N;
  for (int i = 0; i < T; i++) {
    cin >> N;
    cout << memo(N) << "\n";
  }

  return 0;
}