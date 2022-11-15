// LCS 2  // dp  // tabulation
#include <bits/stdc++.h>

using namespace std;

int table[1001][1001] = { 0, };

int LCS(string str1, string str2, int n, int m) {
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        table[i][j] = table[i - 1][j - 1] + 1;
      } else {
        table[i][j] = max(table[i - 1][j], table[i][j - 1]);
      }
    }
  }
  return table[n][m];
}

string findString(int ans, int n, int m, string str1) {
  string str = "";
  while (ans) {
    int current = table[n][m];
    if (current == table[n][m - 1]) {
      m--;
    } 
    else if (current == table[n - 1][m]) {
      n--;
    } 
    else { // current == table[n-1][m-1] + 1
      m--;
      n--;
      ans--; 
      str = str1[n] + str;
    }
  }
  return str;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str1, str2;
  cin >> str1;
  cin >> str2;
  int n, m;
  n = str1.length();
  m = str2.length();
  int ans = LCS(str1, str2, n, m);
  cout << ans << "\n";
  if (ans != 0) {
      cout << findString(ans, n, m, str1) << "\n";
  }
}