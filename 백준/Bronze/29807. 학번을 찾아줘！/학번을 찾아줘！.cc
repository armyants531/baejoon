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
	int T;
	cin >> T;
	vector<int> v(5); // 국, 수, 영, 탐, 제2 
	for (int t = 0; t < T; t++) {
		cin >> v[t];
	}
	int n = 0;
	if (v[0] > v[2]) {
		n += (v[0] - v[2]) * 508;
	} 
	else {
		n += (v[2] - v[0]) * 108;
	}
	if (v[1] > v[3]) {
		n += (v[1] - v[3]) * 212;
	}
	else {
		n += (v[3] - v[1]) * 305;
	}
	if (v[4] > 0) {
		n += v[4] * 707;
	}
	n *= 4763;
	cout << n << "\n";
	
	return 0;
}