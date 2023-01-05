#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 0;
	for (int t = 0; t < 100; t++) {
		int n = 5000;
		vector<ll> cnt(2, 0);
		for (int i = 0; i < n; i++) {
			double x;
			cin >> x;
			if (x <= 0.25 || x > 0.75) {
				cnt[0]++;
			}
			else if (x > 0.25 && x <= 0.75) {
				cnt[1]++;
			}
		}
		if (cnt[0] + 500 < cnt[1]) {
			cout << 'B' << "\n";
		}
		else {
			cout << 'A' << "\n";
		}
	}

	return 0;
}