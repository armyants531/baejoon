// 1620  // hashmap
#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> Map1; // hashmap
unordered_map<int, string> Map2;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin >> N >> M;
  string str;
  for (int i = 1; i <= N; i++) {
    cin >> str;
    Map1[str] = i;
    Map2[i] = str;
  }
  for (int i = 0; i < M; i++) {
    cin >> str;
    if (isdigit(str[0])) {
      cout << Map2[stoi(str)] << "\n";
    }
    else {
      cout << Map1[str] << "\n";
    }
  }

  return 0;
}