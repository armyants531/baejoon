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
	int sum = 0;
	deque<int> dq;
	for (int i = N; i >= 1; i--) {
		if (i % 2 == 0) {
			dq.push_back(i); 
		}
		else {
			dq.push_front(i);
		}		
	}
	int odd = 0;
	int even = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			even += dq[i];
		}
		else {
			odd += dq[i];
		}
	}
	for (int i = 0; i < N; i++) {
		cout << dq[i] << " ";
	}
	cout << "\n";
	if (even > odd) {
		cout << even << "\n";
	}
	else {
		cout << odd << "\n";
	}
	return 0;
}