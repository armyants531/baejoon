// 색종이
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> arr(100, vector<int>(100));
 for (int a = 0; a < n; a++) {
    int x, y;
    cin >> x >> y;
    for (int i = x; i <= x + 9; i++) {
      for (int j = y; j <= y + 9; j++) {
        arr[i][j] = 1;
      }
    }
  }
  int area = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) { 
      if (arr[i][j]) {
        area++;
      }
    }
  }
  cout << area << "\n";
  
  return 0;
}