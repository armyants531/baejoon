#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
using pdd = pair<double, double>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int num = 1;
	int R_max_x = -1000000001;
	int L_min_x = 1000000001;
	int U_max_y = -1000000001;
	int D_min_y = 1000000001;
	for (int i = 1; i <= N; i++) {
		int x, y;
		char d;
		cin >> x >> y >> d;
		if (d == 'R') {
			R_max_x = max(R_max_x, x);
		}
		else if (d == 'L') {
			L_min_x = min(L_min_x, x);
		}
		else if (d == 'U') {
			U_max_y = max(U_max_y, y);
		}
		else {
			D_min_y = min(D_min_y, y);
		}
	}
	//cout << R_max_x << " " << L_min_x << " " << U_max_y << " " << D_min_y << "\n";
	int cnt = 0;
	bool inf = true;
	if (R_max_x + 1 >= L_min_x) {
		inf = false;
	}
	else if (U_max_y + 1 >= D_min_y) {
		inf = false;
	}
	else if (R_max_x != -1000000001 && L_min_x != 1000000001 && U_max_y != -1000000001 && D_min_y != 1000000001) {
		inf = false;
		cnt = (L_min_x - (R_max_x + 1)) * (D_min_y - (U_max_y + 1));
	}
	if (inf) {
		cout << "Infinity" << "\n";
	}
	else {
		cout << cnt << "\n";
	}
	return 0;
}