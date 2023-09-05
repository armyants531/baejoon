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
	int L, P;
	cin >> L >> P;
	int pre = L * P;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		cout << num - pre << " ";
	}
	
	return 0;
}