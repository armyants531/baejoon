// 볼록 껍질  // 기하학  // Graham's scan  // CCW
// https://m.blog.naver.com/kks227/220857597424 참고
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
	int N;
	cin >> N; 
	vector<coord> points;
	int min_y_idx = -1 ;
	ll min_y = 40001;
	for (int i = 0; i < N; i++) {
		ll x, y;
		cin >> x >> y;
		points.push_back({x, y});
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
	//cout << x0 << " " << y0 << "\n";
	// 모든 점을 x에 대해 -x0, y에 대해 -y0 만큼 평행이동
	for (int i = 0; i < N; i++) {
		points[i].x -= x0;
		points[i].y -= y0;
	}
	// 반시계 방향 정렬
	sort(points.begin(), points.end(), compare);
	// 처음 2개의 점의 인덱스를 push
	st.push(0);
	st.push(1);
	for (int next = 2; next <= N - 1; next++) {
		while (st.size() >= 2) { // 스택에 점이 2개 이상일 때
			int B = st.top();
			st.pop();
			int A = st.top();
			// stack 최상단 점 2개와 다음 점의 CCW가 0보다 클 때까지 pop
			if (CCW(points[A], points[B], points[next]) > 0) {
				st.push(B);
				break;
			}
		}
		st.push(next);
	}
	cout << st.size() << "\n";

	return 0;
}