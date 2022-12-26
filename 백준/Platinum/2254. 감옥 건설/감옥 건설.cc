// 감옥 건설  // 기하학  // convex hull  // Graham's scan  // CCW
// 1. 볼록 껍질을 만들고 볼록 껍질 안에 감옥이 포함되면 갯수 + 1한 후, 볼록 껍질 위의 점들을 배열에서 제거
// 2. 포함되지 않으면 종료 
// 3. 1, 2번 반복
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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
	ll Px, Py;
	cin >> N >> Px >> Py;
	vector<coord> points;
	for (int i = 0; i < N; i++) {
		ll x, y;
		cin >> x >> y;
		points.push_back({ x, y });	
	}
	
	int cnt = 0; // 겹 수
	while (points.size() >= 3) {
		int min_y_idx = -1;
		ll min_y = 40001;
		for (int i = 0; i < points.size(); i++) {
			ll x = points[i].x;
			ll y = points[i].y;
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
		for (int i = 0; i < points.size(); i++) {
			points[i].x -= x0;
			points[i].y -= y0;
		}
		Px -= x0;
		Py -= y0;
		// 반시계 방향 정렬
		sort(points.begin(), points.end(), compare);
		deque<int> deq;
		deq.push_back(0);
		deq.push_back(1);
		for (int next = 2; next < points.size(); next++) {
			while (deq.size() >= 2) {
				int B = deq.back();
				deq.pop_back();
				int A = deq.back();
				// deque 맨 뒤 점 2개와 다음 점의 CCW가 0보다 클 때까지 pop
				if (CCW(points[A], points[B], points[next]) > 0) {
					deq.push_back(B);
					break;
				}
			}
			deq.push_back(next);
		}
		// 볼록 껍질 안에 감옥이 포함되는지를 확인
		bool isInside = true;
		if (deq.size() < 3) { // 기둥이 3개 미만이면
			isInside = false;
		}
		else {
			int a = 0;
			int b = 1;
			while (b < deq.size()) {
				int A = deq[a];
				int B = deq[b];
				// 모든 CCW 값이 0보다 커야(반시계 방향) 감옥이 안에 있는 것임 
				if (CCW(points[A], points[B], { Px, Py }) <= 0) {
					isInside = false;
					break;
				}
				a++;
				b++;
			}
			// 마지막 확인
			int A = deq[deq.size() - 1];
			int B = deq[0];
			if (CCW(points[A], points[B], { Px, Py }) <= 0) {
				isInside = false;
			}
		}
		if (isInside) { // 감옥이 안에 있으면
			cnt++;
		}
		else {
			break;
		}

		// deq에 없는 점들로 points 갱신
		int idx = 0;
		deque<coord> temp;
		for (int i = 0; i < points.size(); i++) {
			if (idx < deq.size() && i == deq[idx]) {
				//cout << "(" << points[i].x + x0 << ", " << points[i].y + y0 << ") ";
				idx++;
			}
			else {
				temp.push_back(points[i]);
			}
		}
		points.clear();
		for (int i = 0; i < temp.size(); i++) {
			points.push_back(temp[i]);
			//cout << "(" << points[i].x + x0 << ", " << points[i].y + y0 << ") ";
		}
	}
	cout << cnt << "\n";

	return 0;
}