#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) {
				cout << -1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else {
			double AB = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
			if (AB < max(r1 - r2, r2 - r1)) {
				cout << 0 << "\n";
			}
			else if (AB == (double)max(r1 - r2, r2 - r1)) {
				cout << 1 << "\n";
			}
			else if (AB < r1 + r2) {
				cout << 2 << "\n";
			}
			else if (AB == (double)r1 + r2) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
			
	}

	return 0;
}