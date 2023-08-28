#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	while (N) {
		for (int i = 0; i < N; i++) {
			cout << '*';
		}
		cout << "\n";
		N--;
	}
	
	return 0;
}