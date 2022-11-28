// 10815  // map
// 10815  // map
#include <bits/stdc++.h>

using namespace std;

map<int, int> Map;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin >> N;
  int val;
  for (int i = 0; i < N; i++) {
    cin >> val;
    Map[val] = 1;
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> val;
    cout << Map[val] << " ";
  }
  cout << "\n";

  return 0;
}