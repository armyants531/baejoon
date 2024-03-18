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
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	bool can = true;
	stack<int> st;
	int num = 1;
	int i = 0;
	while (num <= N && i < N) {
		if (v[i] == num) {
			num++;
			i++;
		}
		else if (!st.empty() && st.top() == num) {
			num++;
			st.pop();
		}
		else {
			if (st.empty() || st.top() > v[i]) {
				st.push(v[i]);
				i++;
			}
			else { // st.top() < v[i]
				can = false;
				break;
			}
		}
	}
	if (can) {
		cout << "Nice" << "\n";
	}
	else {
		cout << "Sad" << "\n";
	}
	return 0;
}