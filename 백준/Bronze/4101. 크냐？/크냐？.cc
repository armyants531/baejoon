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
	int a, b;
	cin >> a >> b;
	while (a != 0) {
		if (a > b) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
		}
		cin >> a >> b;
	}

	return 0;
}