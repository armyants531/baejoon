// 포도주 시식  // dp
// n번 째 까지 마실 수 있을 때 최댓값 : dp[n]
// dp[n] = max(dp[n - 1], dp[n - 2] + arr[n], dp[n - 3] + arr[n] + arr[n - 1])
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> dp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  vector<int> arr(N + 1);
  dp.resize(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  dp[1] = arr[1];
  dp[2] = dp[1] + arr[2];
  for (int i = 3; i <= N; i++) {
    dp[i] =
        max({dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i], dp[i - 1]});
  }
  cout << dp[N];

  return 0;
}