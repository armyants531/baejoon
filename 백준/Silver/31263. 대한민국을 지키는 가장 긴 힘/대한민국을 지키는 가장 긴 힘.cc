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
	string s;
	cin >> s;
	int i = 0;
	int cnt = 0;
	while (i < N) {
		if (s[i] == '0') {
			i--;
			continue;
		}
		if (i + 2 < N) {
			string st = s.substr(i, 3);
			if (stoi(st) <= 641) {
				i+= 3;
			}
			else {
				i+= 2;
			}
		}
		else if (i + 1 < N) {
			i+= 2;
		}
		else {
			i++;
		}
		cnt++;
	}
	cout << cnt << "\n";
	return 0;
}