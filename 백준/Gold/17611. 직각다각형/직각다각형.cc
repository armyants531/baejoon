// 직각다각형  // 기하학 
#include <bits/stdc++.h>

using namespace std;
// 0~1은 [0]에, 1~2는 [1]에,..., 999999~1000000은 [999999]에 저장
vector<int> col(1000001); // -500,000 ≤ xi, yi ≤ 500,000
vector<int> row(1000001); 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> coord;
	int min_x = 500001;
	int min_y = 500001;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		coord.push_back({ x, y });
		min_x = min(min_x, x);
		min_y = min(min_y, y);
	}
	for (int i = 1; i < n; i++) {
		int x1 = coord[i - 1].first - min_x;
		int y1 = coord[i - 1].second - min_y;
		int x2 = coord[i].first - min_x;
		int y2 = coord[i].second - min_y;
		if (x1 == x2) {
			if (y1 > y2) {
				for (int j = y2; j < y1; j++) {
					col[j]++;
				}
			}
			else {
				for (int j = y1; j < y2; j++) {
					col[j]++;
				}
			}
		}
		else {
			if (x1 > x2) {
				for (int j = x2; j < x1; j++) {
					row[j]++;
				}
			}
			else {
				for (int j = x1; j < x2; j++) {
					row[j]++;
				}
			}
		}
	}
	// 맨 처음과 맨 마지막 연결
	int x1 = coord[0].first - min_x;
	int y1 = coord[0].second - min_y;
	int x2 = coord[n - 1].first - min_x;
	int y2 = coord[n - 1].second - min_y;
	if (x1 == x2) {
		if (y1 > y2) {
			for (int j = y2; j < y1; j++) {
				col[j]++;
			}
		}
		else {
			for (int j = y1; j < y2; j++) {
				col[j]++;
			}
		}
	}
	else {
		if (x1 > x2) {
			for (int j = x2; j < x1; j++) {
				row[j]++;
			}
		}
		else {
			for (int j = x1; j < x2; j++) {
				row[j]++;
			}
		}
	}

	int h = 0;
	for (int i = 0; i < 1000001; i++) {
		h = max(h, col[i]);
	}
	int v = 0;
	for (int i = 0; i < 1000001; i++) {
		v = max(v, row[i]);
	}
	cout << max(h, v) << "\n";

	return 0;
}