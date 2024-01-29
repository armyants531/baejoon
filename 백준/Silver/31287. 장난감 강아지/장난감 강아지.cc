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
	int N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	//cout << s << "\n";
	int x = 0, y = 0;
	bool has = false;
	int len = s.size();
	if (K != 1) {
		len = min(N * K, N * N);
	}
	for (int i = 0; i < len; i++) {
		if (s[i % N] == 'U') y++;
		else if (s[i % N] == 'D') y--;
		else if (s[i % N] == 'L') x--;
		else x++;
		if (x == 0 && y == 0) {
			has = true;
		} 
	}
	if (has) {
		cout << "YES";
	} 
	else {
		cout << "NO";
	}

	return 0;
}