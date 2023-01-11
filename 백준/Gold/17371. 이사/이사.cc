// 이사  // geometry  // greedy
// 가장 가까운 점과 가장 먼 점 사이의 거리가 최소가 되면 된다.
// 주어진 점들 중 가장 먼 점과의 거리가 최소인 점의 좌표를 구하면 된다. 
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

struct point {
	ld x;
	ld y;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<point> points;
	for (int i = 0; i < N; i++) {
		ld x, y;
		cin >> x >> y;
		points.push_back({x, y});
	}
	ld Hx, Hy;
	ld max_val = 1600000000; // len ^ 2
	for (int i = 0; i < N; i++) {
		ld max_len = 0;
		ld x1 = points[i].x;
		ld y1 = points[i].y;
		for (int j = 0; j < N; j++) {
			if (i != j) {
				ld x2 = points[j].x;
				ld y2 = points[j].y;
				ld len = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
				if (len > max_len) {
					max_len = len;
				}
			}
		}
		if (max_val > max_len) {
			Hx = x1;
			Hy = y1;
			max_val = max_len;
		}
	}
	cout << fixed;
	cout.precision(12);
	cout << Hx << " " << Hy << "\n";

	return 0;
}