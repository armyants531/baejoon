// 생산 시스템 관리  // dp  // knapsack problem
// DP[i][j] = i번째 기계까지 비용 j를 사용했을 때의 최대 확률 * 10^2i
// DP[i][j] = max_k(DP[i – 1][j – k * c_i] * (p_i + k * a_i))
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct machine {
	ll p;
	ll a;
	ll c;
};

vector<vector<ll>> table(10, vector<ll>(30001, 1));

ll knapsack(vector<machine> arr, int N, int B) {
	for (int i = 1; i <= N; i++) {
		//int good_k = 0;
		for (int j = 0; j <= B; j++) {
			// 새로운 물건을 추가 구매하지 않았을 때 확률 * 10^2i
			table[i][j] = table[i - 1][j] * arr[i].p;
			// 새로운 물건을 j - k * c_i >= 0 일 때 까지 넣어보기
			int k = 1;
			while (j - k * arr[i].c >= 0) {
				ll Pi = arr[i].p + k * arr[i].a;
				if (Pi > 100) {
					Pi = 100;
				}
				ll val = table[i - 1][j - k * arr[i].c] * Pi;
				if (table[i][j] < val) {
					table[i][j] = val;
				}
				k++;
				if (Pi == 100) {
					break;
				}
			}
		}
	}
	return table[N][B];
}

vector<int> backtracking(vector<machine> arr, int N, int B, ll ans) {
	int i = N;
	int j = B;
	vector<int> kArr;
	while (i) {
		int k = 0;
		while (j - k * arr[i].c >= 0) {
			ll Pi = arr[i].p + k * arr[i].a;
			if (Pi > 100) {
				Pi = 100;
			}
			if (table[i][j] % Pi == 0 && table[i - 1][j - k * arr[i].c] == table[i][j] / Pi) {
				j -= k * arr[i].c;
				i--;
				kArr.push_back(k);
				break;
			}
			k++;
		}
	}

	return kArr;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, B;
	cin >> N >> B;
	vector<machine> arr;
	arr.push_back({ 0, 0, 0 });
	for (int i = 0; i < N; i++) {
		ll p, a, c;
		cin >> p >> a >> c;
		arr.push_back({p, a, c});
	}
	ll ans = knapsack(arr, N, B);
	cout << ans << "\n";
	vector<int> ans_arr = backtracking(arr, N, B, ans);
	
	for (int i = N - 1; i >= 0; i--) {
		cout << ans_arr[i] << " ";
	}

	return 0;
}