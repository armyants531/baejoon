// 14425  // hashmap
#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> Map; // hashmap

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M, cnt = 0;
  cin >> N >> M;
  string str;
  for (int i = 0; i < N; i++) {
    cin >> str;
    Map[str] = 1;
  }
  for (int i = 0; i < M; i++) {
    cin >> str;
    cnt += Map[str];
  }
  cout << cnt << "\n";

  return 0;
}