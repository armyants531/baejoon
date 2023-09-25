#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

struct dpq {
	int diff, p, q;
};

bool cmp(dpq A, dpq B) {
	return A.diff > B.diff;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int B;
	cin >> B;
	cout << B / 11 * 10 << "\n";
	
	return 0;
}