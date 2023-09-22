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
	if (N == 2) {
		cout << "NO" << "\n";
	}
	else {
		cout << "YES" << "\n";
		cout << 1 << " ";
		if (N >= 3) {
			cout << 3 << " " << 2 << " ";
		}
		for (int i = 4; i <= N; i++) {
			cout << i << " ";
		}
	}
	
	return 0;
}