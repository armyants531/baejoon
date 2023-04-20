// 가장 가까운 두 점  // sweeping  // geometry
// https://www.acmicpc.net/blog/view/25 참고
#include <bits/stdc++.h>

using namespace std;

int dist(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        points[i].first = a;
        points[i].second = b;
    }
    sort(points.begin(), points.end());

    set<pair<int, int>> s;
    int min_d = dist(points[0], points[1]);
    int idx = 0;
    s.insert({ points[0].second, points[0].first });
    s.insert({ points[1].second, points[1].first });

    for (int i = 2; i < points.size(); i++) {
        // 1. x좌표 차이 확인
        while (idx < i) {
            int dx = points[i].first - points[idx].first;
            if (dx * dx >= min_d) { // 범위를 넘어가면
                s.erase({ points[idx].second, points[idx].first }); // 비교하는 점 목록에서 삭제
                idx++; // 다음 탐색 시작점 증가
            }
            else {
                break; // 탐색 범위 좁히기 중단
            }
        }
        // 2. y좌표 차이 확인
        int d = sqrt(min_d) + 1;
        auto start = s.lower_bound({ points[i].second - d, -10001 });
        auto end = s.upper_bound({ points[i].second + d, 10001 });
        for (auto it = start; it != end; it++) {
            auto p = *it;
            min_d = min(min_d, dist(points[i], { p.second, p.first }));
        }
        s.insert({ points[i].second, points[i].first });
    }
    cout << min_d;
}