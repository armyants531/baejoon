#include <bits/stdc++.h>
#define int long long 

using namespace std;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int x;
	int n;
	while (cin >> x) {
		x *= 10000000;  // unit conversion
		cin >> n;
		vector<int> L(n);
		for (int i = 0; i < n; i++) {
			cin >> L[i];
		}
		sort(L.begin(), L.end());
		int low = 0;
		int high = n - 1;
		int l1 = -100000001;
		int l2 = 0;
		while (low < high) {
			int sum = L[low] + L[high];
			if (sum == x) {
				l1 = L[low];
				l2 = L[high];
				break;
			}
			else if (sum > x) {
				high--;
			}
			else {
				low++;
			}
		}
		if (l1 == -100000001) {
			cout << "danger" << "\n";
		}
		else {
			cout << "yes" << " " << l1 << " " << l2 << "\n";
		}
	}

	return 0;
}