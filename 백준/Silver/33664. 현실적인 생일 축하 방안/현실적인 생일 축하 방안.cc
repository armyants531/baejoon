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
	map<string, int> mp;
	int B, N, M;
	cin >> B >> N >> M;
	for (int n = 0; n < N; n++) {
		string i;
		int p;
		cin >> i >> p;
		mp[i] = p;
	}
	int s = 0;
	for (int m = 0; m < M; m++) {
		string j;
		cin >> j;
		s += mp[j];
	}
	if (B >= s) cout << "acceptable" << "\n";
	else cout << "unacceptable" << "\n";
	
	return 0;
}