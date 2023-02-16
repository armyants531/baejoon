// 작성  // Topological sort
#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> adj(10001); // node, time
vector<int> inDegree(10001);
vector<int> cost(10001); // 노드 도착 최대 시간 기록
int T = 0;

void topologySort(int n) {
  queue<int> que;
  // insert the nodes which have 0 indegree
  for (int i = 1; i <= n; i++) {
    if (inDegree[i] == 0) {
      que.push(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    // if queue is empty before visit n node
    if (que.empty()) { // cycle exists
      return;
    }
    int node = que.front();
    que.pop();
    for (auto next : adj[node]) {
      inDegree[next.first]--;
      cost[next.first] = max(cost[next.first], cost[node] + next.second);
      if (inDegree[next.first] == 0) {
        que.push(next.first);
      }
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int t, num;
    cin >> t >> num;
    cost[i] = t;
    T = max(t, T);
    for (int j = 1; j <= num; j++) {
      int n;
      cin >> n;
      if (n > i) {
        adj[i].push_back({n, t});
        inDegree[n]++;
      }
      else { // n < i
        adj[n].push_back({i, t});
        inDegree[i]++;
      }
    }
  }
  topologySort(N);
  for (int i = 1; i <= N; i++) {
    T = max(T, cost[i]);
  }
  cout << T << "\n";
  
  return 0;
}