// 임계경로  // topological sort  // bfs 
// 모두가 도착하는데 걸리는 최소 시간 : 위상 정렬을 통해 최대 시간 구함
// 쉬지 않고 달려야 하는 도로의 개수 : 역방향으로 탐색하며 임계경로를 구하고, 지나온 도로를 세어줌 
#include <bits/stdc++.h>

using namespace std;
int MAX = 10001;

vector<vector<pair<int, int>>> adj1(MAX); // 도시 연결 정보
vector<vector<pair<int, int>>> adj2(MAX); // 역방향
vector<int> inDegree(MAX); // 노드의 진입 차수
vector<int> cost(MAX); // 노드 도착 최대 시간 기록
vector<bool> visited(MAX); // 역방향 탐색 시 노드 방문 여부 확인

// 최대 시간 구하기
void topologySort(int start, int end, int n) { 
    queue<int> que;
    que.push(start);
    for (int i = 1; i <= n; i++) {
        // if queue is empty before visit n node
        if (que.empty()) {
            return;
        }
        int node = que.front();
        que.pop();
        for (auto next : adj1[node]) {
            inDegree[next.first]--;
            // 시간 갱신(최대)
            cost[next.first] = max(cost[next.first], cost[node] + next.second);
            if (inDegree[next.first] == 0) {
                que.push(next.first);
            }
        }
    }
    cout << cost[end] << "\n";
}

// 역방향 탐색하며 경로 개수 세기
void count_load(int start, int end, int n) {
    int cnt = 0;
    queue<int> que;
    que.push(end);
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (auto next : adj2[node]) {
            if (cost[next.first] == cost[node] - next.second) {
                cnt++;
                if (!visited[next.first]) { // 방문하지 않은 경우에만 que에 넣어야 함(중복해서 경로 세는 것 방지)
                    que.push(next.first);
                    visited[next.first] = true;
                }
            }
        }
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int start, end, T;
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> T;
        adj1[start].push_back({ end, T });
        adj2[end].push_back({ start, T });
        inDegree[end]++;
    }
    cin >> start >> end;
    topologySort(start, end, n);
    count_load(start, end, n);

    return 0;
}