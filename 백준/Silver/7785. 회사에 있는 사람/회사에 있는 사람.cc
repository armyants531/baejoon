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
	set<string> s;
	for (int i = 0; i < N; i++) {
		string name, str;
		cin >> name >> str;
		if (str == "enter") {
			s.insert(name);
		}
		else {
			s.erase(name);
		}
	}
	for (set<string>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) {
		cout << *it << "\n";	
	}
	
	return 0;
}