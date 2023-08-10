// 기벡을 안배운다고? 
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
	int N;
	cin >> N;
	vector<pii> v(N);
	map<double, int> mp;
	int xy_zero = 0, x_zero = 0, y_zero = 0;
	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) {
			xy_zero++;
		} 
		else if (x == 0) {
			x_zero++;
		}
		else if (y == 0) {
			y_zero++;
		}
		else {
			mp[y / x]++;
		}
	}
	int ans = xy_zero * (xy_zero - 1) + xy_zero * (N - xy_zero) * 2 + x_zero * y_zero * 2;
	for (auto p : mp) {
		ans += p.se * mp[-1.0 / p.fi]; 
	}
	// i < j이므로 2로 나눔 
	cout << ans / 2 << "\n";
	
	return 0;
}