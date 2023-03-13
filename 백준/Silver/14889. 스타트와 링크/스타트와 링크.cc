// 스타트와 링크  // backtracking
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int N;
int min_diff = 40000;

void dfs(int cnt, int x) {
  visited[x] = true;
  cnt++;
  if (x > N) {
    return;
  }
  if (cnt == N / 2) {
    // add in team
    vector<int> team1;
    vector<int> team2;
    for (int i = 0; i < N; i++) {
      if (visited[i]) {
        team1.push_back(i);
      }
      else {
        team2.push_back(i);
      }
    }
    // cal
    int tot1 = 0;
    for (int i = 0; i < team1.size() - 1; i++) {
      for (int j = i + 1; j < team1.size(); j++) {
        tot1 += (adj[team1[i]][team1[j]] + adj[team1[j]][team1[i]]);
      }
    }
    int tot2 = 0;
    for (int i = 0; i < team2.size() - 1; i++) {
      for (int j = i + 1; j < team2.size(); j++) {
        tot2 += (adj[team2[i]][team2[j]] + adj[team2[j]][team2[i]]);
      }
    }
    int diff = abs((tot2 - tot1));
    min_diff = min(min_diff, diff);
  }
  else {
    // visit the place which not visited yet
    for (int i = x + 1; i < N; i++) {
      if (!visited[i]) {
        dfs(cnt, i);
        visited[i] = false;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  adj.resize(N, vector<int>(N));
  visited.resize(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> adj[i][j];
    }
  }
  dfs(0, 0);
  cout << min_diff << "\n";
}