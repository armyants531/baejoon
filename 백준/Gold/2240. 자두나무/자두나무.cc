#include <bits/stdc++.h>
#define fi first
#define se second
#define INF 2000000000
#define int long long
using namespace std;

using pii = pair<int, int>;

int t[2][1001][32];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, W;
	cin >> T >> W;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= T; j++) {
			t[i][j][W + 1] = -1;
		}
	}
	for (int i = 1; i <= T; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			for (int w = 0; w <= W; w++) {
				t[0][i][w]= max(t[0][i-1][w] + 1, t[1][i-1][w+1] + 1);
			}
			for (int w = 0; w <= W - 1; w++) {
				t[1][i][w] = t[1][i-1][w];
			}
		}
		else {
			for (int w = 0; w <= W; w++) {
				t[0][i][w] = t[0][i-1][w];
			}
			for (int w = 0; w <= W - 1; w++) {
				t[1][i][w]= max(t[0][i-1][w+1] + 1, t[1][i-1][w] + 1);
			}
		}
	}
	/*
	for (int i = 1; i <= T; i++) {
		for (int j = 0; j <= W; j++) {
			cout << t[0][i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 1; i <= T; i++) {
		for (int j = 0; j <= W; j++) {
			cout << t[1][i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/
	int max_cnt = 0;
	for (int i = 0; i <= 1; i++) {
		for (int k = 0; k <= W; k++) {
			max_cnt = max(max_cnt, t[i][T][k]);
		}
	}
	cout << max_cnt << "\n";
	
	return 0;
}