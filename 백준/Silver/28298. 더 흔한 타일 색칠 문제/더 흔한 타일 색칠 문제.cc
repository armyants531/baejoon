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
	int sum = 0;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			vector<int> alp(26);
			for (int di = i; di < N; di += K) {
				for (int dj = j; dj < M; dj += K) {
					alp[A[di][dj] - 'A']++;
				}
			}
			int max_v = 0;
			int max_idx = -1;
			for (int k = 0; k < 26; k++) {
				if (max_v < alp[k]) {
					max_v = alp[k];
					max_idx = k;
				}
			}
			char c = 'A' + max_idx;
			for (int di = i; di < N; di += K) {
				for (int dj = j; dj < M; dj += K) {
					if (A[di][dj] != c) {
						A[di][dj] = c;
						sum++;
					}
				}
			}
		}
	}
	cout << sum << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j];
		}
		cout << "\n";
	}
	
	return 0;	
}