#include <bits/stdc++.h>
#define int long long 

using namespace std;

vector<int> a;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		a.push_back(val);
	}
	sort(a.begin(), a.end());
	int l = 0;
	int h = N - 1;
	int min_sum_abs = 2000000001;
	int ans1;
	int ans2;
	while (l < h) {
		int sum = a[l] + a[h];
		if (sum == 0) {
			ans1 = a[l];
			ans2 = a[h];
			break;
		}
		else if (sum > 0) {
			if (min_sum_abs > sum) {
				min_sum_abs = a[h] + a[l];
				ans1 = a[l];
				ans2 = a[h];
			}
			h--;
		}
		else {
			if (min_sum_abs > -sum) {
				min_sum_abs = -sum;
				ans1 = a[l];
				ans2 = a[h];
			}
			l++;
		}
	}
	cout << ans1 << " " << ans2 << "\n";
	
	return 0;
}