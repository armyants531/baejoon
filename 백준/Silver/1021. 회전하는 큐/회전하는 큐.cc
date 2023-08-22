// 회전하는 큐
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
	int N, M;
	cin >> N >> M;
	deque<int> dq;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		int idx;
		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == a) {
				idx = j;
				break;
			}
		}
		if (idx < dq.size() - idx) {
			int t = idx;
			ans += t;
			while (t--) {
				int num = dq.front();
				dq.pop_front();
				dq.push_back(num);
			}
		}
		else {
			int t = dq.size() - idx;
			ans += t;
			while (t--) {
				int num = dq.back();
				dq.pop_back();
				dq.push_front(num);
			}
		}
		dq.pop_front();
	}
	cout << ans << "\n";

	return 0;
}