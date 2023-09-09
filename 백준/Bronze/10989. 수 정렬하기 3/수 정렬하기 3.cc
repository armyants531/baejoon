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
	int N;
	cin >> N;
	vector<int> a(10001); // count the number
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		a[n]++;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < a[i]; j++) {
			cout << i << "\n";
		}
	}
	
	return 0;
}