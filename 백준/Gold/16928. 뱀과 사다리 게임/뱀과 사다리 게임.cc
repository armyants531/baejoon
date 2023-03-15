// 뱀과 사다리 게임  // dfs
#include <bits/stdc++.h>

using namespace std;

vector<bool> visited(101);
map<int, int> ladder;
map<int, int> snake;
int min_cnt = 100;

void bfs() {   
    queue<pair<int, int>> que;
    que.push({ 1, 0 });
    while (!que.empty()) {
        int x = que.front().first;
        int cnt = que.front().second;
        que.pop();
        if (x == 100) {
            cout << cnt << "\n";
            return;
        }
        for (int i = 1; i <= 6; i++) {
            if (x + i <= 100 && !visited[x + i]) {
                visited[x + i] = true; // x + i 칸 방문처리
                if (ladder[x + i] != 0) {
                    que.push({ ladder[x + i], cnt + 1 }); // ladder[x + i] 칸은 방문처리 하면 안 됨
                }
                else if (snake[x + i] != 0) {
                    que.push({ snake[x + i], cnt + 1 }); // snake[x + i] 칸은 방문처리 하면 안 됨
                }
                else {
                    que.push({ x + i, cnt + 1 });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        ladder[u] = v;
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        snake[u] = v;
    }
    bfs();
}