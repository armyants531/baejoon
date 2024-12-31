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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int odd = 0;
		int even = 0;
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			if (a % 2 == 0) {
				even++;
			}
			else {
				odd++; 
			}
		}
		if (odd > even) {
			if (odd % 2 == 1) {
				cout << "amsminn" << "\n";
			}
			else {
				cout << "heeda0528" << "\n";
			}
		}
		else if (odd < even) {
			if (even % 2 == 1) {
				cout << "amsminn" << "\n";
			}
			else {
				cout << "heeda0528" << "\n";
			}
		}
		else {
			cout << "heeda0528" << "\n";
		}
	}
	return 0;
}