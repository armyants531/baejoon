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
	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;
	int cost = min({A, B, C});
	cost += min(D, E);
	cost -= 50;
	cout << cost;
	return 0;
}