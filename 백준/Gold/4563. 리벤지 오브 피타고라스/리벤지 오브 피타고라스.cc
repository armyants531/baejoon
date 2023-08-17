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
	int A;
	cin >> A;
	while (A) {
		int M = A * A;
		int cnt = 0;
		// A^2 = C^2 - B^2 = (C - B)(C + B)
		for (int s = 1; s < A; s++) {
			if (M % s) continue;
			int l = M / s;
			if (s % 2 != l % 2) continue;
			int B = (l - s) / 2;
			if (B > A) cnt++;
		}
		cout << cnt << "\n";
		cin >> A;
	}
	
	return 0;
}