#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

vector<vector<int>> t(3001, vector<int>(3001, -10000000000000));
vector<int> a(3001);

int dp(int n) {
	for (int i = 0; i < n; i++) {
		t[0][i] = a[0];  
	}
	for (int i = 1; i < n; i++) {
		t[i][i] = t[0][i] + a[i];
		for (int j = i - 1; j >= 1; j--) {
			t[i][j] = max(t[i][j + 1], t[i - j][j] + a[i]);  
		}
	}
	return t[n-1][1];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << dp(n) << "\n";
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << t[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	return 0;
}