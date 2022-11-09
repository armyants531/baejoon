// N과 M (1)  // backtracking  // dfs
#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited(8);
vector<int> series(8);
int N, M;

void dfs(int cnt) {
  if (cnt == M) {
    for (int i = 0; i < M; i++) {
      cout << series[i] << " ";
    }
    cout << "\n";
    return;
  } else {
    for (int i = 0; i < N; i++) {
      if (!visited[i]) {
        visited[i] = true;
        series[cnt] = i + 1;
        dfs(cnt + 1);
        visited[i] = false;
      }
    }
  }
}

int main() {
  // init visited
  for (int i = 0; i < 8; i++) {
    visited.push_back(false);
  }
  cin >> N >> M;

  dfs(0);

  return 0;
}