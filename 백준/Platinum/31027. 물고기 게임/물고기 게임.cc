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
	vector<vector<int>> A(2, vector<int>(N));
	int s = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			s += A[i][j];
		}
	}
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	for (int i = 0; i < N; i++) {
		a += A[0][i];
	}
	for (int i = 0; i < N / 2 + 1; i++) {
		b += A[0][i] + A[1][i];
	}
	for (int i = 0; i < N; i++) {
		c += A[1][i];
	}
	for (int i = 0; i < N / 2; i++) {
		d += A[0][i] + A[1][i];
	}
	//cout << a << " " << b << " " << c << " " << d << "\n";
	int ans = max(max(min(a, b), min(c, d)), d);
	cout << ans << " " << s - ans << "\n";

	return 0;
}