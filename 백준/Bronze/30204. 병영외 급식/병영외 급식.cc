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
	int N, X;
	cin >> N >> X;
	int p, sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> p;
		sum += p;
	}
	if (sum % X == 0) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
	
	return 0;
}