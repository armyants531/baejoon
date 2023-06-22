// d2
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool isPowerOf2(ll n) {
	return (n & (n - 1)) == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	ll m;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == 1) {
			cout << 0 << " " << 0 << "\n";
			continue;
		}
		int x = 0;
		int y = 0;
		ll X = 1;
		ll Y = 1;
		while (Y < m - Y) {
			y++;
			Y *= 2;
		}
		bool exist = false;
		while (Y < m) {
			X = m - Y;
			ll X1 = 1;
			if (isPowerOf2(X)) {
				while (X1 < X) {
					X1 *= 2;
					x++;
				}
				cout << x << " " << y << "\n";
				exist = true;
				break;
			}
			else {
				y++;
				Y *= 2;
			}
		}
		if (!exist) {
			y--;
			Y /= 2;
			X = 1;
			x = 0;
			while (X <= m - Y) {
				X *= 2;
				x++;
			}
			// m 초과
			ll m1 = X + Y;
			int x1 = x;
			int y1 = y;
			//cout << "m1: " << m1 << "\n";
			//cout << x1 << " " << y1 << "\n";

			// m 미만 
			X /= 2;
			x--;
			ll m2 = X + Y;
			int x2 = x;
			int y2 = y;
			//cout << "m2: " << m2 << "\n";
			//cout << x2 << " " << y2 << "\n";

			if (m1 - m < m - m2) {
				cout << x1 << " " << y1 << "\n";
			}
			else {
				cout << x2 << " " << y2 << "\n";
			}
		}
	}

	return 0;
}