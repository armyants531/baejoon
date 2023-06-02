// Escaping  // geometry  // convex hull
// 도둑은 탈출 가능할 때 상하좌우로 쭉 달리면 됨
// 상하좌우로 이동시 경찰한테 잡히는지 판단
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

stack<int> st;

struct coord {
	ll x;
	ll y;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<coord> points;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		points.push_back({ x, y });
	}
	int x0, y0;
	cin >> x0 >> y0;
	bool up = true;
	bool down = true;
	bool right = true;
	bool left = true;
	for (int i = 0; i < N; i++) {
		x = points[i].x;
		y = points[i].y;
		if (y > y0) {
			if (abs(x - x0) <= y - y0) {
				up = false;
			}
		}
		else if (y < y0) {
			if (abs(x - x0) <= y0 - y) {
				down = false;
			}
		}
		
		if (x > x0) {
			if (abs(y - y0) <= x - x0) {
				right = false;
			}
		}
		else if (x < x0) {
			if (abs(y - y0) <= x0 - x) {
				left = false;
			}
		}
	}
	if (up || down || right || left) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
	return 0;
}