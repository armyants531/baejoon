// 문제집  // Topological sort
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(32001);
vector<int> inDegree(32001);
vector<int> ans;
int T = 0;

void topologySort(int n) {
  priority_queue<int, vector<int>, greater<int>> pq;
  // insert the nodes which have 0 indegree
  for (int i = 1; i <= n; i++) {
    if (inDegree[i] == 0) {
      pq.push(i);
    }
  }
  while (!pq.empty()) {
    int node = pq.top();
    pq.pop();
    ans.push_back(node);
    for (auto next : adj[node]) {
      inDegree[next]--;
      if (inDegree[next] == 0) {
        pq.push(next);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    int A, B;
    cin >> A >> B;
    adj[A].push_back(B);
    inDegree[B]++;
  }
  topologySort(N);
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  
  return 0;
}