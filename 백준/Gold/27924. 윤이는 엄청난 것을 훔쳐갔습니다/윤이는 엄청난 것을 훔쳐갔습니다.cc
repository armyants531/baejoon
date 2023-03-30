// 윤이는 엄청난 것을 훔쳐갔습니다  // dfs  // greedy
// '윤이와 리프 노드와의 거리 < 두 경찰과 리프 노드와의 거리 중 작은 값'인 리프 노드가 존재하는가?
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj(200001);
vector<vector<bool>> visited(3, vector<bool>(200001, false));
vector<vector<int>> leef_dist(3, vector<int>(200001, 200001)); //  리프 노드와 떨어진 거리 저장

void dfs(int x, int cnt, int num) { // x : 노드 번호, cnt : 거리, num : 캐릭터 번호 
    visited[num][x] = true;
    if (adj[x].size() == 1) { // 리프 노드이면
        leef_dist[num][x] = cnt;
    }
    for (auto y : adj[x]) {
        if (!visited[num][y]) {
            dfs(y, cnt + 1, num);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int u, v;
    for (int i = 1; i <= N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int a, b, c;
    cin >> a >> b >> c;
    dfs(a, 0, 0);
    dfs(b, 0, 1);
    dfs(c, 0, 2);
    // 리프 노드와의 거리 비교
    bool canEscape = false;
    for (int i = 1; i <= N; i++) {
        if (leef_dist[0][i] < leef_dist[1][i] && leef_dist[0][i] < leef_dist[2][i]) {
            canEscape = true;
            //cout << i << "\n";
            break;
        }
    }
    if (canEscape) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
    return 0;
}