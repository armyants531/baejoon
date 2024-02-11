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
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v[i] = {x, y};
	}
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 0; j < N; j++) {
			if (v[j].fi > v[i].fi && v[j].se > v[i].se) {
				cnt++;	
			}
		}
		cout << cnt << " ";
	}
	return 0;
}