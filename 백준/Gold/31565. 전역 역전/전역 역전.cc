#include <bits/stdc++.h> 
#define int long long
using namespace std;

vector<string> a;
vector<int> ans;
vector<vector<int>> dp(101, vector<int>(10001));

int date_cal(int y, int m, int d) {
	int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
		mon[2] = 29;
	}
	int tot = 0;
	for (int i = 1; i < m; i++) {
		tot += mon[i];
	}
	tot += d;
	return tot;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int Y1, Y2, M1, M2, D1, D2;
	cin >> Y1 >> M1 >> D1;
	cin >> Y2 >> M2 >> D2;
	int T, N;
	cin >> T >> N;
	vector<pair<int, int>> v;
	v.push_back({0, 0});
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == 1) {
			int C, V;
			cin >> C >> V;
			v.push_back({C, V});
		} 
		else if (num == 2) {
			int C, G;
			cin >> C >> G;
			v.push_back({C, G});
		}
		else {
			int C, M;
			cin >> C >> M;
			v.push_back({C, M * 30});
		}
	}
	int date1 = date_cal(Y1, M1, D1);
	int date2 = date_cal(Y2, M2, D2);
	int diff = date2 - date1;
	for (int y = Y1; y < Y2; y++) {
		if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
			diff += 366;
		}
		else {
			diff += 365;
		}
	}
	for (int j = 0; j <= T; j++) {
		dp[0][j] = -diff;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= T; j++) {
			dp[i][j] = dp[i-1][j];
			if (j - v[i].first >= 0) {
				dp[i][j] = max(dp[i][j], dp[i-1][j - v[i].first] + v[i].second);
			}
		}
	}
	/*
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= T; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	int max_v = dp[N][T];
	if (max_v < 0) cout << -max_v << "\n";
	else cout << max_v << "\n";
	
	return 0;
}