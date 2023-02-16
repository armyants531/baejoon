// 인간-컴퓨터 상호작용  // prefix sum
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  int q;
  cin >> q;
  int n = s.length();
  vector<vector<int>> A(n + 1, vector<int>(26, 0));
  for (int i = 1; i <= n; i++) {
    int idx = (int)(s[i - 1] - 'a');
    for (int j = 0; j < 26; j++) {
      A[i][j] = A[i - 1][j]; 
    }
    A[i][idx]++;
  }
  for (int i = 0; i < q; i++) {
    char c;
    int l, r;
    cin >> c >> l >> r;
    if (s[l] == c) {
      cout << A[r + 1][c - 'a'] - A[l + 1][c - 'a'] + 1 << "\n";
    }
    else {
      cout << A[r + 1][c - 'a'] - A[l + 1][c - 'a'] << "\n";
    }
    
  }

  return 0;
}