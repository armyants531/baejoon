#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	if (N == M && N == 1) {
		cout << 1 << "\n" << 1 << "\n";
	}
	else if (N == 1) {
		cout << 2 << "\n";
		for (int i = 0; i < M; i++) {
			cout << i % 2 + 1 << " ";
		}
		cout << "\n";
	}
	else if (M == 1) {
		cout << 2 << "\n";
		for (int i = 0; i < N; i++) {
			cout << i % 2 + 1 << "\n";
		}	
	}
	else {
		cout << 4 << "\n";
		vector<vector<int>> a(1000, vector<int>(1000));
		for (int i = 0; i < 1000; i += 4) {
			for (int j = 0; j < 1000; j += 2) {
				a[i][j] = 1;
				a[i + 1][j] = 3;
				a[i + 2][j] = 2;
				a[i + 3][j] = 3;
				a[i][j + 1] = 2;
				a[i + 1][j + 1] = 4;
				a[i + 2][j + 1] = 1;
				a[i + 3][j + 1] = 4;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}