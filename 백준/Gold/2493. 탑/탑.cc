// 탑
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	stack<pair<int, int>> st;
	vector<int> arr(500001);
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		while (!st.empty()) {
			if (st.top().first >= h) {
				cout << st.top().second << " ";
				break;
			}
			else {
				st.pop();
			}
		}
		if (st.empty()) {
			cout << 0 << " ";
		}
		st.push({h, i});
	}

	return 0;
}