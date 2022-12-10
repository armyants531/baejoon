// 주사위  // greedy
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll N;
  cin >> N;
  vector<ll> dice(6);
  for (int i = 0; i < 6; i++) {
    cin >> dice[i];
  }
  if (N == 1) {
    cout << accumulate(dice.begin(), dice.end(), 0) - *max_element(dice.begin(), dice.end()) << "\n";
  }
  else {
    ll A = dice[0];
    ll B = dice[1];
    ll C = dice[2];
    ll D = dice[3];
    ll E = dice[4];
    ll F = dice[5];
    ll min1 = *min_element(dice.begin(), dice.end());
    ll min2 = min({A + B, A + C, A + D, A + E, B + C, B + D, B + F, C + E, C + F, D + E, D + F, E + F});
    ll min3 = min({A + B + C, A + B + D, A + C + E, A + D + E, B + C + F, B + D + F, C + E + F, D + E + F});
    ll sum = 4 * min3 + (8 * N - 12) * min2 + (5 * N * N - 16 * N + 12) * min1;
    cout << sum << "\n";
  }
  return 0;
}