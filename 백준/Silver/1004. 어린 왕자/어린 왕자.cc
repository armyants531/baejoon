// 어린 왕자  // 기하학
#include <iostream>
#include <cmath> // sqrt: 제곱근

using namespace std;

typedef struct PlanetarySys {
	int Cx;
	int Cy;
	int r;
} sys;

// 두 점 간 거리를 구하는 함수
double distance(int x1, int y1, int x2, int y2) {
	int pow_dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	return sqrt(pow_dist);
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int n;
		cin >> n;
		sys arr[50];
		for (int j = 0; j < n; j++) {
			cin >> arr[j].Cx >> arr[j].Cy >> arr[j].r;
		}
		// 두 점 중 한 점은 원 안에, 다른 한 점은 원 밖에 있는 경우에 진입/이탈 횟수가 증가한다.
		// (출발점과 원의 중심 사이의 거리 < 원의 반지름 && 도착점과 원의 중심 사이의 거리 > 원의 반지름) || (출발점과 원의 중심 사이의 거리 > 원의 반지름 && 도착점과 원의 중심 사이의 거리 < 원의 반지름)  
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			double dist1 = distance(x1, y1, arr[j].Cx, arr[j].Cy);
			double dist2 = distance(x2, y2, arr[j].Cx, arr[j].Cy);
			if ((dist1 < arr[j].r && dist2 > arr[j].r) || (dist1 > arr[j].r && dist2 < arr[j].r)) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}