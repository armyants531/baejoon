// 내리막 길  // dp  // dfs
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> dp;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int M, N;

int dfs(int y, int x) {
  if (dp[y][x] != -1) {
    return dp[y][x];
  }
  if (y == M - 1 && x == N - 1) { // end point
    return dp[y][x] = 1;
  }
  dp[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < M && ny >= 0 && nx < N && nx >= 0 && arr[ny][nx] < arr[y][x]) {
      dp[y][x] += dfs(ny, nx);           
    }
  }
  return dp[y][x];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> M >> N;
  arr.resize(M, vector<int>(N));
  dp.resize(M, vector<int>(N, -1));
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }
  cout << dfs(0, 0) << "\n";
  /*
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
  */
  return 0;
}