#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool isPowerOf2(ll n) {
	return (n & (n-1)) == 0;
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
		int x = 0;
		int y = 0;
		ll X = 1;
		ll Y = 1;
		while (Y < m - Y) {
			y++;
			Y *= 2;
		}
		while (true) {
			X = m - Y;
			ll X1 = 1;
			if (isPowerOf2) {
				while (X1 < X) {
					X1 *= 2;
					x++;
				}
				cout << x << " " << y << "\n";
				break;
			}
			else {
				y++;
				Y *= 2;
			}
		}
	}
	
	return 0;
}