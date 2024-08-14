#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int a[31][31];
bool v[31][31];
int b[31][31];

int N;
	
vector<int> pre(60);
	
int dp(int x, int y, int l) {
	if (x >= N || y >= N) return 0;
	if (b[x][y] != -1) {
		return b[x][y];
	}
	return b[x][y] = max(dp(x+1, y, l-1), dp(x, y+1, l-1)) + a[x][y] * pre[l];
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;
	int nu = 1;
	for (int i = 0; i <= 59; i++) {
		pre[i] = nu;
		nu *= 2;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			b[i][j] = -1;
		}
	}
	dp(0, 0, 2 * (N-1));
	
	cout << b[0][0];
	return 0;
}