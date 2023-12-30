#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int cnt = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'O') {
				cnt++;
			}
		}
		if (cnt > M / 2) {
			ans++;
		}
	}	
	cout << ans << "\n";

	return 0;
}