#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

vector<vector<int>> a(101, vector<int>(101));
vector<vector<int>> b(101, vector<int>(101));
int cnt = 0;
int N;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cnt = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
		}
	}
	b[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k < i; k++) {
				if (a[i - k][j] == k) {
					b[i][j] += b[i - k][j];
				}
			}
			for (int k = 1; k < j; k++) {
				if (a[i][j - k] == k) {
					b[i][j] += b[i][j - k];
				}
			}
		}
	}
	cout << b[N][N] << "\n";

	return 0;
}