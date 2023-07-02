#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<char>> A(N, vector<char>(M));
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			A[i][j] = s[j];
		}
	}
	vector<vector<vector<int>>> B(K, vector<vector<int>>(K, vector<int>(26)));
	for (int i = 0; i < N; i += K) {
		for (int j = 0; j < M; j += K) {
			for (int di = 0; di < K; di++) {
				for (int dj = 0; dj < K; dj++) {
					B[di][dj][A[i + di][j + dj] - 'A']++;
				}
			}
		}
	}
	int sum = 0;
	vector<vector<char>> C(K, vector<char>(K));
	int repeat = N * M / (K * K);
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			int max_idx = -1;
			int max_v = 0;
			for (int k = 0; k < 26; k++) {
				if (B[i][j][k] > max_v) {
					max_idx = k;
					max_v = B[i][j][k];
				}
			}
			sum += repeat - max_v;
			C[i][j] = (char)(max_idx + 'A');
		}
	}
	cout << sum << "\n";
	vector<vector<char>> ans(N, vector<char>(M));
	for (int i = 0; i < N; i += K) {
		for (int j = 0; j < M; j += K) {
			for (int di = 0; di < K; di++) {
				for (int dj = 0; dj < K; dj++) {
					ans[i + di][j + dj] = C[di][dj];
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ans[i][j];
		}
		cout << "\n";
	}

	return 0;
}