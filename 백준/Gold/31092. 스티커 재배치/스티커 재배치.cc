#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

struct info {
	int s, d, a;
};
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	vector<pair<char, int>> v;
	vector<int> alp_cost(26, 1001); // 구입 비용  

	for (int i = 0; i < M; i++) {
		char s;
		int d, a;
		cin >> s >> d >> a;
		v.push_back({ s, d });
		if (alp_cost[(int)(s - 'a')] > a) {
			alp_cost[(int)(s - 'a')] = a;
		}
	}
	vector<pair<char, int>> b(N);
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		b[i] = { v[n - 1].fi, n - 1 };
	}
	string S;
	cin >> S;
	vector<int> alp_s(26);
	for (int i = 0; i < K; i++) {
		alp_s[(int)(S[i] - 'a')]++;
	}
	vector<int> alp(26); // b의 알파벳 개수  
	for (int i = 0; i < N; i++) {
		alp[(int)(b[i].fi - 'a')]++;
	}
	// 불가능 
	bool can = true;
	for (int i = 0; i < 26; i++) {
		if (alp_s[i] > alp[i]) {
			if (alp_cost[i] == 1001) {
				can = false;
				break;
			}
		}
	}
	if (!can) {
		cout << -1 << "\n";
	}
	else {
		int ans = 20000000;
		for (int i = 0; i <= N - K; i++) {
			int cost = 0;
			vector<int> alp_num(26); // 뗀 스티커  
			// 스티커 떼기  
			for (int j = 0; j < K; j++) {
				if (b[i + j].fi != S[j]) {
					cost += v[b[i + j].se].se;
					alp_num[(int)(v[b[i + j].se].fi - 'a')]++;
				}
			}
			
			//bool det = false; // 빈 칸 발생
			// 다른 곳 스티커 모두 떼기
			vector<priority_queue<int, vector<int>, greater<int>>> alp_more(26);
			for (int j = 0; j <= i - 1; j++) {
				alp_more[(int)(v[b[j].se].fi - 'a')].push(v[b[j].se].se);
			}
			for (int j = i + K; j <= N - 1; j++) {
				alp_more[(int)(v[b[j].se].fi - 'a')].push(v[b[j].se].se);
			}
			// 스티커 붙이기  
			for (int j = 0; j < K; j++) {
				if (v[b[i + j].se].fi != S[j]) {
					int idx = (int)(S[j] - 'a');
					if (alp_num[idx] > 0) { // 무료 
						alp_num[idx]--;
					}
					else {
						// 다른 곳에서 뗄 수 있는지 
						if (!alp_more[idx].empty() && alp_more[idx].top() < alp_cost[idx]) {
							cost += alp_more[idx].top();
							alp_more[idx].pop();
						}
						else {
							cost += alp_cost[idx];
						}
					}
				}
			}
			ans = min(ans, cost);
		}
		cout << ans << "\n";
	}

	return 0;
}