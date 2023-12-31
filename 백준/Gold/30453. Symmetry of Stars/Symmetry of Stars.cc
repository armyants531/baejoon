#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int ans = 0;
	unordered_map<ll, int> mp;
	vector<pair<ll, ll>> v(N);
	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		mp[2 * x + 2000000002 * y]++;
		v[i] = {x, y};
	}	
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			mp[(v[i].fi + v[j].fi) + 1000000001 * (v[i].se + v[j].se)] += 2;
		}
	}
	for (auto a : mp) {
		//cout << a.fi.fi << " " << a.fi.se << " " << a.se << "\n";
		if (ans < a.se) {
			ans = a.se;
		}
	}
	cout << ans << "\n";

	return 0;
}