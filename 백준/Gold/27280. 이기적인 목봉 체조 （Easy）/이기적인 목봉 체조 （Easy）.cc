#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<pair<ll, ll>> arr;
vector<vector<ll>> f; // 구간 [i,j]의 훈련병이 들 수 있는 무게
vector<vector<ll>> DP; // DP[i][j] = i번 째 병사를 끝으로 j번 째 그룹이 묶였을 때 무게 최대값

void tabulation(int N, int M) {
	for (int i = 0; i < N; i++) {
		DP[i][0] = f[0][i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < M; j++) {
			for (int k = 1; k <= i; k++) {
				DP[i][j] = max(DP[i][j], DP[k - 1][j - 1] + f[k][i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		ll h, s;
		cin >> h >> s;
		arr.push_back({ h, s });
	}
	// 구간 [i,j]의 훈련병이 들 수 있는 무게를 전처리
	f.resize(N, vector<ll>(N, 0));
	for (int i = 0; i < N; i++) {
		ll max_h = arr[i].first;
		ll w = arr[i].second;
		f[i][i] = w;
		for (int j = i + 1; j < N; j++) {
			if (max_h < arr[j].first) {
				max_h = arr[j].first;
				w = arr[j].second;
				f[i][j] = w;
			}
			else if (max_h == arr[j].first) {
				w += arr[j].second;
				f[i][j] = w;
			}
			else { // max_h > arr[i].first
				f[i][j] = f[i][j - 1];
			}
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << f[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	DP.resize(N, vector<ll>(M, 0));
	tabulation(N, M);
	cout << DP[N-1][M-1] << "\n";
}