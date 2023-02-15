// 줄 세우기 // topological sort
// https://m.blog.naver.com/ndb796/221236874984
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(32001);
vector<int> inDegree(32001);
vector<int> ans(32001);

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
    if (que.empty()) {
      return;
    }
    int node = que.front();
    que.pop();
    ans[i] = node;
    for (auto next : adj[node]) {
      inDegree[next]--;
      if (inDegree[next] == 0) {
        que.push(next);
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
  int A, B;
  for (int i = 0; i < M; i++) {
    cin >> A >> B;
    adj[A].push_back(B);
    inDegree[B]++;
  }
  topologySort(N);
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << " ";
  }
  
  return 0;
}