// A → B  // dfs
#include <bits/stdc++.h>

using namespace std;

int min_count = 1000000000;
void dfs(int cnt, int A, int B) {
  cnt++;
  if (B == A) {
    min_count = min(min_count, cnt);          
  }
  else if (B > A) {
    if (A <= 500000000) {
      dfs(cnt, A * 2, B);
    }
    if (A < 100000000) {
      dfs(cnt, A * 10 + 1, B);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int A, B;
  cin >> A >> B;
  dfs(0, A, B);
  if (min_count == 1000000000) {
    cout << - 1 << "\n";
  }
  else {
    cout << min_count << "\n";
  }
  
  return 0;
}