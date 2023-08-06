// E
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
int p = 1000000007;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		int r1 = 0;
		int tr1 = 0, tr2 = 0;
		int p;
		for (int j = 0; j < 2; j++) {
			cin >> p;
			if (p > r1) r1 = p;
		}
		for (int j = 0; j < 5; j++) {
			cin >> p;
			if (p > tr1) {
				tr2 = tr1;
				tr1 = p; 
			}
			else if (p > tr2) {
				tr2 = p;
			}
		}
		arr[i] = r1 + tr1 + tr2;
	}
	sort(arr.begin(), arr.end());
	cout << arr[N - 1] << "\n";
	
	return 0;
}