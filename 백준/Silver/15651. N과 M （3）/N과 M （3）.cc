// N과 M (3)  // backtracking  // dfs
#include <iostream>
#include <vector>

using namespace std;

vector<int> series(7);
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
      series[cnt] = i + 1;
      dfs(cnt + 1);
    }
  }
}

int main() {
  cin >> N >> M;

  dfs(0);

  return 0;
}