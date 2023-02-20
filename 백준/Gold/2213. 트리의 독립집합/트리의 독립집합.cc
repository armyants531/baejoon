// 트리의 독립집합  // tree dp
#include <bits/stdc++.h>

using namespace std;

vector<bool> visited(10001, false);
vector<int> val(10001);
vector<vector<int>> adj(10001);
vector<vector<int>> dp(10001, vector<int>(2, 0)); // 0: 불포함, 1: 포함
vector<int> trace;
vector<bool> check(10001);

void dfs(int node) {
    visited[node] = true;
    dp[node][0] = 0; // 현재 노드 불포함
    dp[node][1] = val[node]; // 포함
    for (auto next : adj[node]) {
        if (!visited[next]) {
            dfs(next);
            dp[node][0] += max(dp[next][1], dp[next][0]);
            dp[node][1] += dp[next][0];
        }
    }  
}

void backtracking(int node, int pre) { // 현재 노드, 이전 노드 포함 여부
    check[node] = true;
    if (pre == 0) { // 이전 노드 불포함
        if (dp[node][1] > dp[node][0]) { // 현재 노드 포함
            trace.push_back(node);
            for (auto next : adj[node]) {
                if (!check[next]) {
                    backtracking(next, 1);
                }
            }
        }
        else { // 현재 노드 불포함
            for (auto next : adj[node]) {
                if (!check[next]) {
                    backtracking(next, 0);
                }
            }
        }
    }
    else { // 이전 노드 포함
        for (auto next : adj[node]) {
            if (!check[next]) {
                backtracking(next, 0);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> val[i];
    }
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);

    if (dp[1][0] > dp[1][1]) {
        cout << dp[1][0] << "\n";
    }
    else {
        cout << dp[1][1] << "\n";
    }
    backtracking(1, 0);
    sort(trace.begin(), trace.end());
    for (auto a : trace) {
        cout << a << " ";
    }
}