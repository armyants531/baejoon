// 인덕션  // dp
#include <bits/stdc++.h>

using namespace std;

// table[i][a][b][c] = button click number: i(food number), a, b, c(temperature) 
int table[2][10][10][10]; 
vector<int> T;

void dp(int N) {
  int cnt0 = min(T[0], 10 - T[0]);
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      for (int k = 0; k <= 9; k++) {
        table[0][i][j][k] = 25001;
      }
    }
  }
  table[0][T[0]][0][0] = cnt0;
  table[0][0][T[0]][0] = cnt0;
  table[0][0][0][T[0]] = cnt0;
  for (int i = 1; i < N; i++) {
    for (int i = 0; i <= 9; i++) {
      for (int j = 0; j <= 9; j++) {
        for (int k = 0; k <= 9; k++) {
          table[1][i][j][k] = 25001;
        }
      }
    }
    for (int a = 0; a <= 9; a++) {
      for (int b = 0; b <= 9; b++) {
        for (int c = 0; c <= 9; c++) {
          table[1][T[i]][b][c] = min(table[1][T[i]][b][c], table[0][a][b][c] + min((a - T[i] + 10) % 10, (T[i] - a + 10) % 10));
          table[1][a][T[i]][c] = min(table[1][a][T[i]][c], table[0][a][b][c] + min((b - T[i] + 10) % 10, (T[i] - b + 10) % 10));
          table[1][a][b][T[i]] = min(table[1][a][b][T[i]], table[0][a][b][c] + min((c - T[i] + 10) % 10, (T[i] - c + 10) % 10));
        }
      }
    }
    for (int i = 0; i <= 9; i++) {
      for (int j = 0; j <= 9; j++) {
        for (int k = 0; k <= 9; k++) {
          table[0][i][j][k] = table[1][i][j][k];
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  int t;
  for (int i = 0; i < N; i++) {
    cin >> t;
    T.push_back(t);
  }
  if (N == 1) {
    cout << min(T[0], 10 - T[0]) << "\n";
  }
  else {
    dp(N);
    int min_cnt = 25001;
    for (int i = 0; i <= 9; i++) {
      for (int j = 0; j <= 9; j++) {
        for (int k = 0; k <= 9; k++) {
          min_cnt = min(min_cnt, table[1][i][j][k]);
        }
      }
    }
    cout << min_cnt << "\n";
  }
  
  return 0;
}