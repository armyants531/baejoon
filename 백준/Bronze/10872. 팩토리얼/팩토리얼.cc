#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
using pdd = pair<double, double>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int num = 1;
	for (int i = 1; i <= N; i++) {
		num *= i;
	}
	cout << num << "\n";
	
	return 0;
}