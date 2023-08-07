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
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<int> row(N + 1);
	vector<int> col(M + 1);
	while (Q--) {
		int ord;
		cin >> ord;
		if (ord == 1) {
			int r, v;
			cin >> r >> v;
			row[r] += v;
		}
		else {
			int c, v;
			cin >> c >> v;
			col[c] += v;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << row[i] + col[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}