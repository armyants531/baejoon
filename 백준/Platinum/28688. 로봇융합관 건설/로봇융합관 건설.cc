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
		int N, M;
		cin >> N >> M;
		if (N <= 2 || M <= 2) {
			cout << "First" << "\n";
		} 
		else if (N % 2 == 1 && M % 2 == 1) {
			cout << "First" << "\n";
		}
		else {
			cout << "Second" << "\n";
		}
	}
	
	return 0;
}