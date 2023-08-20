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
	double x, y;
	set<double> s;
	bool xzero = false;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		if (x == 0) xzero = true;
		else {
			s.insert(y / x);
		}
	}
	int cnt = s.size();
	if (xzero) cnt++;
	cout << cnt << "\n"; 
	
	return 0;
}