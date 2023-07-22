#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef long long ll;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	string card;
	cin >> card;
	vector<int> s(N + 1); // 누적된 스페이드 수
	for (int i = 1; i <= N; i++) {
		s[i] = s[i - 1];
		if (card[i - 1] == 'S') {
			s[i]++;
		}
	}
	for (int k = 1; k <= N; k++) {
		int cnt = 0;
		for (int i = k; i <= N; i += (k - s[i])) {
			cnt++;
			if (k == s[i]) {
				break;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}