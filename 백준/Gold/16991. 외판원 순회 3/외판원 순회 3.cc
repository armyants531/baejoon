// 외판원 순회 3  // DP  // bitmasking  // TSP
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
// cache[current][status]: 현재 있는 도시가 current이고, 이미 방문한 도시들의 집합이 status일 때 방문하지 않은 나머지 도시들을 모두 방문한 뒤 출발 도시(0)으로 돌아올 때 드는 최소 비용
ld cache[16][1 << 16] = {0, };
vector<vector<ld>> cost(16, vector<ld>(16));
ld MAX = 32000000.0;

ld tsp(int current, int status, int N) {
    // 방문 처리
    status |= (1 << current);
    if (status == (1 << N) - 1) { // 모두 방문 시
        return cost[current][0];
    }
    ld& min_cost = cache[current][status];
    if (min_cost != 0) { // 최소 비용 이미 구함
        return min_cost;
    }
    min_cost = MAX;
    for (int next = 0; next < N; next++) {
        if ((status & (1 << next)) == 0) { // 방문하지 않았으면 
            min_cost = min(min_cost, tsp(next, status, N) + cost[current][next]);
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
    vector<pair<ld, ld>> points;
    for (int i = 0; i < N; i++) {
        ld x, y;
        cin >> x >> y; 
        points.push_back({ x, y });
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cost[i][j] = sqrt((points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second));
        }
    }
    cout << fixed;
    cout.precision(13);
    cout << tsp(0, 0, N) << "\n";

    return 0;
}