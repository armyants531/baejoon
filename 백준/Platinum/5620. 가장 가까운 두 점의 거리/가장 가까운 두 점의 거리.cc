// 가까운 두 점의 거리  // sweeping  // geometry
#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<pii> p(N);
	for (int i = 0; i < N; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p.begin(), p.end()); // x좌표에 대해 오름차순
	int ans = dist(p[0], p[1]);
	set<pair<int, int>, y_order> posi; // y좌표에 대해 오름차순 
	posi.insert(p[0]);
	posi.insert(p[1]);
	int idx = 0; // 다음 탐색 시작점 
	for (int i = 2; i < N; i++) {
		pii cur = p[i];
		// x좌표 차이 확인, 탐색 범위 좁히기		
		while (idx < i) {
			int dx = cur.first - p[idx].first;
			if (dx * dx >= ans) {
				posi.erase(p[idx]); // 비교 목록에서 삭제
				idx++; 
			}
			else {
				break;  
			}
		}
		// y좌표 차이 확인
		int d = sqrt(ans) + 1;
		// y좌표가 y - d보다 크거나 같은 점 중 인덱스가 가장 작은 점
		auto lower = posi.lower_bound({ -10001 , p[i].second - d});  
		// y좌표가 y + d보다 큰 점 중 인덱스가 가장 작은 점
		auto upper = posi.upper_bound({ 10001 , p[i].second + d});
		for (auto it = lower; it != upper; it++) {
			pii dot = *it;
			int len = dist(p[i], dot);
			ans = min(ans, len);
		}
		posi.insert(p[i]); // 비교 목록에 추가 
	}
	cout << ans << "\n";
	
	return 0;
}