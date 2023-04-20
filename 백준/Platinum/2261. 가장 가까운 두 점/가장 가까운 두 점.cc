// 가장 가까운 두 점  // sweeping  // geometry
// https://www.acmicpc.net/blog/view/25 참고
#include <bits/stdc++.h>

using namespace std;

int dist(const pair<int, int> &a, const pair<int, int> &b) { // 거리의 제곱 계산
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
} 

// y에 대해 오름차순
struct y_order {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second < b.second;
	}
};

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> points(n);
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		points[i].first = x;
		points[i].second = y;
	}
	sort(points.begin(), points.end()); // x에 대해 오름차순
	/*
	for (int i = 0; i < n; i++) {
		cout << "{" << points[i].first << ", " << points[i].second << "} ";
	}
	cout << "\n";
	*/
	int ans = dist(points[0], points[1]); // 최소 거리 제곱
	
	set<pair<int, int>, y_order> posi; 
	posi.insert(points[0]);
	posi.insert(points[1]); // possible set에 처음 두 점 추가
	int search_idx = 0; // points 배열이 x에 대해 오름차순 정렬됨 -> 다음 탐색 시작점 설정 
	for (int i = 2; i < n; i++) {
		// 1. x좌표 차이 확인
		pair<int, int> cur = points[i];
		while (search_idx < i) {
			pair<int, int> p = points[search_idx];
			int dx = cur.first - p.first;
			if (dx * dx >= ans) { // 범위를 넘어가면
				posi.erase(p); // 비교하는 점 목록에서 삭제
				search_idx++; // 다음 탐색 시작점 증가
			}
			else { break; } // 탐색 범위 좁히기 중단
		}
		// 2. y좌표 차이 확인
		int d = sqrt(ans) + 1;
		// possible set에서 이분 탐색으로 y좌표 차이가 ans 이하인지 확인 
		// y좌표가 y - d 보다 크거나 같은 점 중 인덱스가 가장 작은 점
		pair<int, int> p1 = { -10001, cur.second - d };
		auto lower = posi.lower_bound(p1);
		// y좌표가 y + d 보다 큰 점 중 인덱스가 가장 작은 점
		pair<int, int> p2 = { 10001, cur.second + d };
		auto upper = posi.upper_bound(p2);
		for (auto it = lower; it != upper; it++) {
			auto p = *it;
			int temp = dist(p, cur);
			ans = min(ans, temp); // 최소 거리 갱신
		}
		// posi set에 현재 점 추가
		posi.insert(cur);
		/*
		for (auto it = posi.begin(); it != posi.end(); it++) {
			pair<int, int> p = *it;
			cout << '{' << p.first << ", " << p.second << '}' << " ";
		}
		cout << "\n";
		*/
	}
	cout << ans;

	return 0;
}