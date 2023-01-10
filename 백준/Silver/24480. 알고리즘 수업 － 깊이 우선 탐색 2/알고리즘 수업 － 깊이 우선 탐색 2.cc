// 알고리즘 수업 - 깊이 우선 탐색 2  // dfs
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N, M, R;

vector<vector<int>> adj(100001);
vector<int> visited(100001);
int cnt = 1;

void dfs(int node) {
  visited[node] = cnt;
  cnt++;
  for (auto next : adj[node]) {
    if (!visited[next]) {
      dfs(next);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M >> R;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= N; i++) {
    sort(adj[i].begin(), adj[i].end(), greater<int>());
  }
  dfs(R);
  for (int i = 1; i <= N; i++) {
    cout << visited[i] << "\n";
  }
  
  return 0;
}