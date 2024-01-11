#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
// t[i][j]: i번째 app까지 비활성화 가능할 때
// j의 cost까지 사용가능한 경우, 최대 메모리 확보량 
vector<vector<int>> t(101, vector<int>(10001)); 

int knapsack(int tot, vector<pii> app, int N, int M) {
	int min_cost = 10001;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= tot; j++) { // cost가 0인 것도 고려! 
			if (j - app[i].se >= 0) {
				t[i][j] = max(t[i-1][j], app[i].fi + t[i-1][j-app[i].se]);
			}
			else {
				t[i][j] = t[i-1][j];
			}
			if (t[i][j] >= M) {
				min_cost = min(min_cost, j);
			}
		}
	}
	return min_cost;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<pii> app(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> app[i].fi;
	}
	int tot_cost = 0;
	for (int i = 1; i <= N; i++) {
		cin >> app[i].se;
		tot_cost += app[i].se;
	}
	cout << knapsack(tot_cost, app, N, M) << "\n";

	return 0;
}