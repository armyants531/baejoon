// 단순 다각형  // 기하학  // convex hull  // Graham's scan  // CCW
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct coord {
	ll x;
	ll y;
	int idx;
};

int CCW(coord A, coord B, coord C) {
	// overflow prevention
	// (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
	long long val = B.x * C.y - B.x * A.y - A.x * C.y - B.y * C.x + A.x * B.y + A.y * C.x;
	if (val > 0) // 반시계
		return 1;
	else if (val < 0) // 시계
		return -1;
	else // 일직선 상에 있을 때
		return 0;
}

// 반시계 방향 정렬
// 1순위: 기울기에 대해 오름차순, 2순위: y좌표에 대해 오름차순, 3순위: x좌표에 대해 오름차순
bool compare(coord a, coord b) {
	if (a.y * b.x != a.x * b.y) {
		return a.y * b.x < a.x * b.y;
	}
	else if (a.y != b.y) {
		return a.y < b.y;
	}
	else {
		return a.x < b.x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		vector<coord> points;
		int min_y_idx = -1;
		ll min_y = 10001;
		for (int i = 0; i < n; i++) {
			ll x, y;
			cin >> x >> y;
			points.push_back({ x, y, i });
			if (y < min_y) {
				min_y = y;
				min_y_idx = i;
			}
			else if (y == min_y) { // y좌표가 같으면
				if (x < points[min_y_idx].x) { // x좌표가 더 작은 것 선택
					min_y_idx = i;
				}
			}
		}
		// y값이 가장 작은 점의 좌표를 원점으로 잡기(y좌표가 같으면 x좌표가 더 작은 것 선택)
		ll x0 = points[min_y_idx].x;
		ll y0 = points[min_y_idx].y;

		// 모든 점을 x에 대해 -x0, y에 대해 -y0 만큼 평행이동
		for (int i = 0; i < n; i++) {
			points[i].x -= x0;
			points[i].y -= y0;
		}
		// 반시계 방향 정렬
		sort(points.begin(), points.end(), compare);
		/*
		for (int i = 0; i < n; i++) {
			cout << points[i].idx << " ";
		}
		cout << "\n";
		*/
		int idx_same_slop = n - 1;
		while (CCW(points[0], points[n - 1], points[idx_same_slop]) == 0) {
			idx_same_slop--;
		}
		for (int i = 0; i <= idx_same_slop; i++) {
			cout << points[i].idx << " ";
		}
		for (int i = n - 1; i > idx_same_slop; i--) {
			cout << points[i].idx << " ";
		}
		cout << "\n";
	}

	return 0;
}