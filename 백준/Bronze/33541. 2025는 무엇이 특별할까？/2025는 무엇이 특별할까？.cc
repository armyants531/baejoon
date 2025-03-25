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
	int x;
	cin >> x;
	bool ex = false;
	for (int i = 1; x + i <= 9999; i++) {
		int p = (x+i) / 100;
		int q = (x+i) % 100;
		if (x+i == (p + q) * (p + q)) {
			cout << x+i << "\n";
			ex = true;
			break; 
		}
	}
	if (!ex) {
		cout << -1 << "\n";
	}
	
	return 0;
}