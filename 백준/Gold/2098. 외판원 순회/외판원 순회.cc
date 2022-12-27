// 외판원 순회  // DP  // bitmasking  // TSP(Travelling Salesman Problem)
// https://withhamit.tistory.com/246 참고(설명 좋음)
// https://codecollector.tistory.com/1225 참고
// 0번 도시에서 출발해서 도시를 방문할 때 마다 cost 값을 더해줌
// 모든 도시를 방문하면 마지막 도시에서 0번 도시로 돌아올 때 필요한 cost를 반환
// 돌아오는 경로가 없으면 (cost == 0) INF를 반환
// 구한 경로 중 cost 합이 최소인 것을 반환
#include <bits/stdc++.h>

using namespace std;
// cache[current][status]: 현재 있는 도시가 current이고, 이미 방문한 도시들의 집합이 status일 때 방문하지 않은 나머지 도시들을 모두 방문한 뒤 출발 도시(0)으로 돌아올 때 드는 최소 비용
int cache[16][1 << 16]; 
vector<vector<int>> cost(16, vector<int>(16));
int INF = 16000001;

int memo(int current, int status, int N) {
    // 방문 처리
    status |= (1 << current);
    if (status == (1 << N) - 1) { // if all visited
        if (cost[current][0]) { // current -> 0 경로가 존재하면 
            return cost[current][0];
        }
        else {
            return INF;
        }
    }
    int& ans = cache[current][status];
    if (ans != -1) { // 이미 최소 비용을 구했으면
        return ans;
    }
    ans = INF;
    for (int next = 0; next < N; next++) {
        if (cost[current][next] != 0 && (status & (1 << next)) == 0) { // if can visit && not visited
            ans = min(ans, memo(next, status, N) + cost[current][next]);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }
    cout << memo(0, 0, N) << "\n";

    return 0;
}