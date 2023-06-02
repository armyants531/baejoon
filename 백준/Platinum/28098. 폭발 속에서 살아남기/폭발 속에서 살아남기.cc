// 폭발 속에서 살아남기  // geometry  // convex hull
// 원점에 대하여 반시계 방향으로 폭발점을 P1, P2,..., PN 이라 할 때
// 선분 OPi와 선분 OPi+1 가 이루는 각이 파이 이상인 경우가 존재하면 탈출 가능하다
// 이는 N개의 점과 원점으로 볼록껍질을 구성했을 때 원점이 볼록껍질 위에 존재하는가를 알아보면 된다.
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

stack<int> st;

struct coord {
	ll x;
	ll y;
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
		return a.y * b.x < a.x* b.y;
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
	int N;
	cin >> N;
	vector<coord> points;
	int min_y_idx = -1;
	ll min_y = 1000000001;
	for (int i = 0; i < N; i++ ) {
		ll x, y;
		cin >> x >> y;
		points.push_back({ x, y });
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
	// 마지막에 원점 추가
	points.push_back({0, 0});
	if (0 < min_y) {
		min_y = 0;
		min_y_idx = N;
	}
	else if (0 == min_y) { // y좌표가 같으면
		if (0 < points[min_y_idx].x) { // x좌표가 더 작은 것 선택
			min_y_idx = N;
		}
	}

	// y값이 가장 작은 점의 좌표를 원점으로 잡기(y좌표가 같으면 x좌표가 더 작은 것 선택)
	ll x0 = points[min_y_idx].x;
	ll y0 = points[min_y_idx].y;

	// 모든 점을 x에 대해 -x0, y에 대해 -y0 만큼 평행이동
	for (int i = 0; i <= N; i++) {
		points[i].x -= x0;
		points[i].y -= y0;
	}
	// 반시계 방향 정렬
	sort(points.begin(), points.end(), compare);
	// 처음 2개의 점의 인덱스를 push
	st.push(0);
	st.push(1);
	for (int next = 2; next <= N; next++) {
		while (st.size() >= 2) {
			int B = st.top();
			st.pop();
			int A = st.top();
			// stack 최상단 점 2개와 다음 점의 CCW가 0보다 클 때까지 pop -> 0이상이면 됨(사잇각이 파이 이상)
			if (CCW(points[A], points[B], points[next]) >= 0) {
				st.push(B);
				break;
			}
		}
		st.push(next);
	}
	// stack에 원점 존재 여부 확인 -> (-x0, -y0) 가 존재하는가?
	bool isExist = false;
	while (!st.empty()) {
		int idx = st.top();
		st.pop();
		if (points[idx].x == -x0 && points[idx].y == -y0) {
			isExist = true;
			break;
		}
	}
	if (isExist) {
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";
	}

	return 0;
}