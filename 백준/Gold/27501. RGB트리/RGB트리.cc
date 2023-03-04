#include <bits/stdc++.h>

using namespace std;

vector<bool> visited(500001, false);
vector<vector<int>> adj(500001);
vector<vector<int>> dp(500001, vector<int>(3, 0)); // 0: R, 1: G, 2: B
vector<int> trace(500001);

void dfs(int node) {
    visited[node] = true;
    for (auto child : adj[node]) {
        if (!visited[child]) {
            dfs(child);
            dp[node][0] += max(dp[child][1], dp[child][2]);
            dp[node][1] += max(dp[child][0], dp[child][2]);
            dp[node][2] += max(dp[child][0], dp[child][1]);
        }
    }
}

vector<bool> check(500001, false);
void backtracking(int node, int pre_color) {
    check[node] = true;
    if (pre_color == 0) {
        if (dp[node][1] >= dp[node][2]) {
            trace[node] = 1;
            for (auto child : adj[node]) {
                if (!check[child]) {
                    backtracking(child, 1);
                }
            }
        }
        else {
            trace[node] = 2;
            for (auto child : adj[node]) {
                if (!check[child]) {
                    backtracking(child, 2);
                }
            }
        }  
    }
    else if (pre_color == 1) {
        if (dp[node][0] >= dp[node][2]) {
            trace[node] = 0;
            for (auto child : adj[node]) {
                if (!check[child]) {
                    backtracking(child, 0);
                }
            }
        }
        else {
            trace[node] = 2;
            for (auto child : adj[node]) {
                if (!check[child]) {
                    backtracking(child, 2);
                }
            }
        }
    }
    else {
        if (dp[node][0] >= dp[node][1]) {
            trace[node] = 0;
            for (auto child : adj[node]) {
                if (!check[child]) {
                    backtracking(child, 0);
                }
            }
        }
        else {
            trace[node] = 1;
            for (auto child : adj[node]) {
                if (!check[child]) {
                    backtracking(child, 1);
                }
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
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        dp[i][0] = r;
        dp[i][1] = g;
        dp[i][2] = b;
    }
    dfs(1);
    int max_idx;
    if (dp[1][0] >= dp[1][1] && dp[1][0] >= dp[1][2]) {
        max_idx = 0;
        cout << dp[1][0] << "\n";
    }
    else if (dp[1][1] >= dp[1][0] && dp[1][1] >= dp[1][2]) {
        max_idx = 1;
        cout << dp[1][1] << "\n";
    }
    else {
        max_idx = 2;
        cout << dp[1][2] << "\n";
    }
    trace[1] = max_idx;
    for (auto child : adj[1]) {
        if (!check[child]) {
            backtracking(child, max_idx);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (trace[i] == 0) cout << 'R' << "";
        else if (trace[i] == 1) cout << 'G' << "";
        else cout << 'B' << "";
    }
}