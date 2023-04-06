// 선 긋기  // 정렬  // 스위핑
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<pair<int, int>> point;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		point.push_back({ x, y });
	}
	sort(point.begin(), point.end()); // x, y순 오름차순 정렬 
	int len = 0;
	int left, right;
	left = point[0].first;
	right = point[0].second;
	for (int i = 1; i < N; i++) {
		if (point[i].first <= right) {
			right = max(right, point[i].second);
		}
		else { // right < point[i].first
			// 지금까지 거리 더해줌
			len += (right - left);
			left = point[i].first;
			right = point[i].second;
		}
	}
	len += (right - left);
	cout << len << "\n";
}