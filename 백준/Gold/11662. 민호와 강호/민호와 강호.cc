// 민호와 강호  // geometry  // ternary search 풀이
#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef long long ll;
double ax, ay, bx, by, cx, cy, dx, dy;

// 거리 제곱 = (ax - cx + t(bx - ax - dx + cx))^2 + (ay - cy + t(by - ay - dy + cy))^2
double dist(double t) {
	double diff_x = ax - cx + t * (bx - ax - dx + cx);
	double diff_y = ay - cy + t * (by - ay - dy + cy);
	return diff_x * diff_x + diff_y * diff_y;
}

double tsearch(double low, double high) {
	double min_d = 100000000;
	int cnt = 0;
	while (low <= high && cnt < 300) {
		double p = (2 * low + high) / 3;
		double q = (low + 2 * high) / 3;
		if (dist(p) >= dist(q)) {
			low = p;
		}
		else {
			high = q;
		}
		cnt++;
	}
	return sqrt(dist(low));
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
	cout << fixed;
	cout.precision(10);
	cout << tsearch(0, 1) << "\n";

	return 0;
}