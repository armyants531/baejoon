// 최종 순위  // Topological sort
// 팀을 vertex, 팀 간 우열관계를 edge로 설정
#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> adj;
vector<int> inDegree(501);
vector<int> result(501);

int topologySort(int n) {
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
      return -1;       // impossible
    }
    int node = que.front();
    que.pop();
    result[i] = node;
    for (int i = 1; i <= n; i++) {
      if (adj[node][i]) {
        inDegree[i]--;
        if (inDegree[i] == 0) {
          que.push(i);
        }
      }
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N, M;
    cin >> N;
    adj.resize(N + 1, vector<bool>(N + 1));
    inDegree.resize(N + 1);
    result.resize(N + 1);
    vector<int> arr;
    for (int i = 0; i < N; i++) {
      int a;
      cin >> a;
      arr.push_back(a);
    }
    // 모든 우열 관계 고려!
    for (int i = 0; i < N - 1; i++) {
      for (int j = i + 1; j < N; j++) {
        adj[arr[i]][arr[j]] = true;
        inDegree[arr[j]]++;
      }
    }
    cin >> M;
    int A, B;
    for (int i = 0; i < M; i++) {
      cin >> A >> B;
      if (adj[A][B] == false) {
        adj[A][B] = true;
        adj[B][A] = false;
        inDegree[B]++;
        inDegree[A]--;
      }
      else {
        adj[B][A] = true;
        adj[A][B] = false;
        inDegree[A]++;
        inDegree[B]--;
      }
    }
    int key = topologySort(N);
    if (key == 1) {
      for (int i = 1; i <= N; i++) {
        cout << result[i] << " ";
      }
      cout << "\n";
    } else {
      cout << "IMPOSSIBLE"
           << "\n";
    }
    inDegree.clear();
    result.clear();
    adj.clear();
  }
  return 0;
}