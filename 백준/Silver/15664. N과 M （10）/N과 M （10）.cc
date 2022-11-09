// N과 M (10)  // backtracking  // dfs
#include <algorithm> // sort
#include <iostream>
#include <vector>

using namespace std;

vector<int> series(8);
vector<int> arr;
vector<bool> visited(8);
int N, M;

void dfs(int cnt, int pre_idx) {
  if (cnt == M) {
    for (int i = 0; i < M; i++) {
      cout << series[i] << " ";
    }
    cout << "\n";
    return;
  } else {
    int last_ele = 0;
    for (int i = pre_idx; i < N; i++) {
      if (!visited[i] && arr[i] != last_ele) {
        visited[i] = true;
        series[cnt] = arr[i];
        last_ele = arr[i];
        dfs(cnt + 1, i);
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
  for (int i = 0; i < N; i++) {
    int val;
    cin >> val;
    arr.push_back(val);
  }
  sort(arr.begin(), arr.end());
  
  dfs(0, 0);

  return 0;
}