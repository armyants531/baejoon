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
	int N, M, T;
	cin >> N >> M >> T;
	vector<int> g(N + 2); // gipo
	vector<int> p(N + 2); // previous gipo
	while (T--) {
		int y, k;
		cin >> y >> k;
		g[y] = min(g[y] + k, M);
		for (int i = 1; i <= N; i++) {
			p[i] = g[i];
		}
		for (int i = 1; i <= N; i++) {
			int val = (int)(floor((double)p[i-1] / 5) + floor((double)p[i] / 5) + floor((double)p[i+1] / 5));
			//cout << "val: " << floor((double)p[i-1] / 5) << " " << floor((double)p[i] / 5) << " " << floor((double)p[i+1] / 5) << "\n";
			g[i] = min(M, val);
		}
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			sum += g[i];
		}
		cout << sum << "\n";
	}
	return 0;
}