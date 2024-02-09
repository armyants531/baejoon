#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int x, y;
	cin >> x >> y;
	int day = 0;
	for (int i = 1; i < x; i++) {
		day += a[i];
	}
	day += (y - 1);
	day %= 7;
	if (day == 0) {
		cout << "MON" << "\n";
	}
	else if (day == 1) {
		cout << "TUE" << "\n";
	}
	else if (day == 2) {
		cout << "WED" << "\n";
	}
	else if (day == 3) {
		cout << "THU" << "\n";
	}
	else if (day == 4) {
		cout << "FRI" << "\n";
	}
	else if (day == 5) {
		cout << "SAT" << "\n";
	}
	else {
		cout << "SUN" << "\n";
	}
	return 0;
}