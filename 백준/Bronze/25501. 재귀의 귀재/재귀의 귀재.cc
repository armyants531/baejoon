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
	int T;
	cin >> T;
	vector<string> v(T);
	for (int i = 0; i < T; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < T; i++) {
		int n = v[i].size();
		int cnt = 1;
		bool isPal = true;
		for (int j = 0; j < n / 2; j++) {
			if (v[i][j] == v[i][n-1-j]) {
				cnt++;
			}
			else {
				isPal = false;
				break;
			}
		}
		if (isPal) {
			cout << 1 << " " << cnt << "\n";
		}
		else {
			cout << 0 << " " << cnt << "\n";
		}
	}

	return 0;
}