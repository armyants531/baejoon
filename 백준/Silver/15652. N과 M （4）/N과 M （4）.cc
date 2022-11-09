// N과 M (4)  // backtracking  // dfs
#include <iostream>
#include <vector>

using namespace std;

vector<int> series(7);
int N, M;

void dfs(int cnt, int pre_num) { // bigger or equal to pre_num
  if (cnt == M) {
    for (int i = 0; i < M; i++) {
      cout << series[i] << " ";
    }
    cout << "\n";
    return;
  } else {
    for (int i = pre_num - 1; i < N; i++) {
      series[cnt] = i + 1;
      dfs(cnt + 1, i + 1);
    }
  }
}

int main() {
  cin >> N >> M;

  dfs(0, 1);

  return 0;
}