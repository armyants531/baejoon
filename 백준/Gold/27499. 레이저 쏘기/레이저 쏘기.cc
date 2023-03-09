// 레이저 쏘기  // 해시맵 
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M, K;
  cin >> N >> M >> K;
  double x, y;
  map<double, int> mp;
  vector<double> slope;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    for (int j = 0; j <= (K - 1) / 2; j++) {
      double sl = y / (x + 2 * j * M);
      mp[sl]++;
      slope.push_back(sl);
    }
    for (int j = 1; j <= K / 2; j++) {
      double sl = y / (2 * j * M - x);
      mp[sl]++;
      slope.push_back(sl);
    }
  }
  int max_cnt = 0;
  for (int i = 0; i < slope.size(); i++) {
    max_cnt = max(max_cnt, mp[slope[i]]);
  }
  cout << max_cnt << "\n";
}