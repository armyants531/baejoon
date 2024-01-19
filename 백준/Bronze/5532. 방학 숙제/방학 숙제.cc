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
	int L;
	double A, B, C, D;
	cin >> L >> A >> B >> C >> D;
	double m = max(A / C, B / D);
	cout << L - ceil(m);
	return 0;
}