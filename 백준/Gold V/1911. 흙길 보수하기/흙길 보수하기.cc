#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, L;
	cin >> N >> L;
	int cnt = 0;
	int x = 0;
	vector<pll> v(N);
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		v[i] = {s, e};
	}
	sort(v.begin(), v.end());
	x = v[0].fi - 1;
	for (int i = 0; i < N; i++) {
		if (x < v[i].fi) {
			x = v[i].fi - 1;
			if (x < v[i].se - 1) {
				int tmp = ceil((double)(v[i].se - 1 - x) / L);
				cnt += tmp;
				x += tmp * L;
			}
		} 
		else {
			if (x < v[i].se - 1) {
				int tmp = ceil((double)(v[i].se - 1 - x) / L);
				cnt += tmp;
				x += tmp * L;
			}	
		}
	}
	cout << cnt << "\n";
	
	return 0;
}