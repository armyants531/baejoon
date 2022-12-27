// 외판원 순회 2  // dp  // bactracking
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int MAX = 10000001;

int dfs(int curr, int N) {
    visited[curr] = true;
    bool allVisited = true;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            allVisited = false;
        }
    }
    if (allVisited) {
        if (adj[curr][0]) {
            return adj[curr][0];
        }
        else {
            return MAX;
        }
    }
    int min_cost = MAX;
    for (int next = 0; next < N; next++) {
        if (!visited[next] && adj[curr][next] != 0) { // 방문하지 않았고, 갈 수 있으면
            min_cost = min(min_cost, dfs(next, N) + adj[curr][next]);
            visited[next] = false;
        }
    }

    return min_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    adj.resize(N, vector<int>(N));
    visited.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }
    cout << dfs(0, N) << "\n";

	return 0;
}
