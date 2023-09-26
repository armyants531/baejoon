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
	int n = s.size();
	vector<char> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = s[i];
	}
	for (int i = 1; i < N; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (v[j] != s[j]) {
				v[j] = '?';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << v[i];
	}
	
	return 0;
}