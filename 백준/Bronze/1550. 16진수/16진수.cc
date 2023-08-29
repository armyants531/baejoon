#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int sum = 0;
	int mul = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		if ('0' <= s[i] && s[i] <= '9') {
			sum += mul * (s[i] - '0');
		}
		else {
			sum += mul * (s[i] - 'A' + 10);
		}
		mul *= 16;
	}
	cout << sum << "\n";
	
	return 0;
}