#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
vector<int> A(1024);
vector<vector<int>> t(10);

void func(int l, int r, int level) {
	if (l > r) return;
	int m = (l + r) / 2;
	t[level].push_back(A[m]);
	func(l, m - 1, level + 1);
	func(m + 1, r, level + 1);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int K;
	cin >> K;
	int N = pow(2, K) - 1;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	func(0, N - 1, 0);
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < t[i].size(); j++) {
			cout << t[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}