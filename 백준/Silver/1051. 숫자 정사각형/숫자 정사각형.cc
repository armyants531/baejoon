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
	int N, M;
	cin >> N >> M;
	vector<string> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int len = max(N, M) - 1;
	bool find = false;
	for (int l = len; l >= 0; l--) {
		for (int i = 0; i < N - l; i++) {
			for (int j = 0; j < M - l; j++) {
				if (v[i][j] == v[i][j + l] && v[i][j] == v[i + l][j] && v[i][j] == v[i + l][j + l]) {
					find = true;
					len = l;
					break;
				}
			}
			if (find) break;
		}
		if (find) break;
	}
	cout << (len + 1) * (len + 1) << "\n";
	
	return 0;
}