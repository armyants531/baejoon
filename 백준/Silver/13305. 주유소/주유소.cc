// 주유소  // greedy
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  vector<int> road(N - 1);
  for (int i = 0; i < N - 1; i++) {
    cin >> road[i];
  }
  int val;
  int min_val = 1000000001;
  ll cost = 0;
  for (int i = 0; i < N - 1; i++) {
    cin >> val;
    min_val = min(min_val, val);
    cost += min_val * road[i];
  }
  cin >> val;
  
  cout << cost << "\n";
  return 0;
}