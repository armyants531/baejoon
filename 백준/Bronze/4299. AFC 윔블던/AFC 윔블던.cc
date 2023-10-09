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
	int s, m;
	cin >> s >> m;
	if ((s + m) % 2 == 1 || s < m) {
		cout << -1 << "\n";
	}
	else {
		cout << (s + m) / 2 << " " << (s - m) / 2 << "\n";
	}
	
	return 0;
}