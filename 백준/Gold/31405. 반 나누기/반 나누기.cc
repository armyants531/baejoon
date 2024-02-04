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
	vector<pdd> v(N+1);
	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		v[i] = {x, y};
	}
	v[N] = v[0];
	double s = 0;
	for (int i = 0; i < N; i++) {
		s += v[i].fi * v[i + 1].se;
		s -= v[i + 1].fi * v[i].se; 
	}
	s = abs(s);
	//cout << s << "\n";
	int idx;
	double s1 = 0;
	for (int i = 1; i <= N - 1; i++) {
		double tmp = abs(v[0].fi * v[i].se + v[i].fi * v[i+1].se + v[i+1].fi * v[0].se - v[i].fi * v[0].se - v[i+1].fi * v[i].se - v[0].fi * v[i+1].se);
		s1 += tmp;
		if (s / 2 < s1) {
			idx = i;
			s1 -= tmp;
			break;
		}
	}
	
	cout << "YES" << "\n";
	double alpha = (0.5 * s - s1) / (v[idx].fi * v[idx+1].se - v[idx].fi * v[0].se + v[idx+1].fi * v[0].se - v[idx+1].fi * v[idx].se + v[0].fi * v[idx].se - v[0].fi * v[idx+1].se); 
	cout << fixed;
	cout.precision(12);
	cout << 1 << " " << 0 << "\n";
	cout << idx + 1 << " " << alpha << "\n";
	
	return 0;
}