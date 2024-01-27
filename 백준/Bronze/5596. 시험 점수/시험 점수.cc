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
	int S = 0;
	int T = 0;
	for (int i = 0; i < 4; i++) {
		int a;
		cin >> a;
		S += a;
	}
	for (int i = 0; i < 4; i++) {
		int b;
		cin >> b;
		T += b;
	}
	cout << max(S, T);
	return 0;
}