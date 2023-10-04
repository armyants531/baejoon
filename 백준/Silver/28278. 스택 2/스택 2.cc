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
	stack<int> st;
	for (int i = 0; i < N; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int X;
			cin >> X;
			st.push(X);
		}
		else if (cmd == 2) {
			if (!st.empty()) {
				int t = st.top();
				st.pop();
				cout << t << "\n";	
			}
			else {
				cout << -1 << "\n";
			}	
		}
		else if (cmd == 3) {
			cout << st.size() << "\n";
		}
		else if (cmd == 4) {
			if (st.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else {
			if (!st.empty()) {
				int t = st.top();
				cout << t << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
	}
	
	return 0;
}