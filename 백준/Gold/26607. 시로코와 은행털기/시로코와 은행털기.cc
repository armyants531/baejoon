// 시로코와 은행털기  // dp  // tabulation
// 팀의 능력치 = t(x*k - t)
// table[i][j][t]: i번째 사람까지 볼 때, j명을 골라 그들의 a값의 합이 t가 되면 1 아니면 0
// table[i][j][t] = table[i-1][j][t] | table[i-1][j-1][t-a_i]
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k, x;
// table[i][j][t]: i번째 사람까지 볼 때, j명을 골라 그들의 a값의 합이 t가 되면 1 아니면 0
vector<vector<vector<ll>>> table;

ll knapsack(vector<int> a, int Sa) {
	ll max_val = 0;
	// 1명 고르는 경우 초기화
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= i; j++) {
			table[i][1][a[j]] = 1;
		}
	}
	for (ll i = 2; i <= n; i++) {
		for (ll j = 2; j <= i; j++) {
			if (j > k) {
				continue;
			}
			for (ll t = 0; t <= Sa; t++) {
				if (t - a[i] >= 0) {
					table[i][j][t] = (table[i - 1][j][t] | table[i - 1][j - 1][t - a[i]]);
				}
				else {
					table[i][j][t] = table[i - 1][j][t];
				}
			}
		}
	}
	for (ll t = 0; t <= Sa; t++) {
		if (table[n][k][t] == 1) {
			max_val = max(max_val, t * (x * k - t));
		}
	}
	return max_val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k >> x;
	
	vector<int> ob; // a값 리스트
	ob.push_back(0);
	int Sa = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		ob.push_back(a);
		Sa += a;
	}
	table.resize(n + 1, vector<vector<ll>>(k + 1, vector<ll>(Sa + 1)));
	cout << knapsack(ob, Sa) << "\n";
	
	return 0;
}