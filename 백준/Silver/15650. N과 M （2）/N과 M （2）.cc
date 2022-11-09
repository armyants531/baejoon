// N과 M (2)  // backtracking  // dfs
#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited(8);
vector<int> series(8);
int N, M;

void dfs(int cnt, int pre_num) { // search bigger num than pre_num  
  if (cnt == M) {
    for (int i = 0; i < M; i++) {
      cout << series[i] << " ";
    }
    cout << "\n";
    return;
  } else {
    for (int i = pre_num; i < N; i++) {
      if (!visited[i]) {
        visited[i] = true;
        series[cnt] = i + 1;
        dfs(cnt + 1, i + 1);
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

  dfs(0, 0);

  return 0;
}