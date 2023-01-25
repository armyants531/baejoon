#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> prefix;
	vector<int> arr;
	prefix.push_back(0);
	arr.push_back(0);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		arr.push_back(t);
		sum += t;
		prefix.push_back(sum);
	}
	int T = prefix[N]; // 주기
	vector<vector<int>> sol(M, vector<int>(2));
	for (int i = 0; i < M; i++) {
		int p, r, c;
		cin >> p >> r >> c;
		int time = prefix[p - 1];
		if (time < c) {
			int x = ceil((double)(c - time) / T);
			time += x * T;
		}
		sol[i][0] = time;
		if (p < r) {
			sol[i][1] = time + (prefix[r - 1] - prefix[p - 1]);
		}
		else { // r < p
			if (p == N) {
				sol[i][1] = time + arr[N] + prefix[r - 1];
			}
			else {
				sol[i][1] = time + T - (prefix[p - 1] - prefix[r - 1]);
			}
		}
	}
	int max_t = 0;
	for (int i = 0; i < M; i++) {
		//cout << sol[i][0] << " " << sol[i][1] << "\n";
		max_t = max(sol[i][1], max_t);
	}
	cout << max_t << "\n";
}