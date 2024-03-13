#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		int M, F;
		cin >> M >> F;
		if (M == 0 && F == 0) {
			break;
		}
		cout << M + F << "\n";
	}
	
	return 0;
}