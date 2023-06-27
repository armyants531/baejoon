// Marked - Numbered  // stack
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int C;
	cin >> C;
	int m;
	stack<pair<int, int>> st; // {m, idx}
	st.push({ 0, 0 });
	bool corr = true;
	int len = 1;
	vector<int> ans(C + 1);
	for (int i = 1; i <= C; i++) {
		cin >> m;
		if (st.top().first + 1 < m) {
			corr = false;
		}
		else if (st.top().first <= m) {
			st.push({ m, i });
		}
		else {
			queue<int> idx_q;
			while (st.top().first > m) {
				int idx = st.top().second;
				st.pop();
				idx_q.push(idx);
			}
			while (!idx_q.empty()) {
				ans[idx_q.front()] = idx_q.size();
				idx_q.pop();
			}
			st.push({ m, i });
		}
	}
	int end = st.top().first;
	for (int i = end - 1; i >= 0; i--) {
		queue<int> idx_q;
		while (st.top().first > i) {
			int idx = st.top().second;
			st.pop();
			idx_q.push(idx);
		}
		while (!idx_q.empty()) {
			ans[idx_q.front()] = idx_q.size();
			idx_q.pop();
		}
	}
	if (!corr) {
		cout << -1 << "\n";
	}
	else {
		for (int i = 1; i <= C; i++) {
			cout << ans[i] << " ";
		}
	}

	return 0;
}