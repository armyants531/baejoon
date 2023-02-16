#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int mid = M / 2;
	vector<vector<ll>> P(M, vector<ll>(N));
	vector<ll> F(N);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> P[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		vector<ll> arr;
		for (int j = 0; j < M; j++) {
			arr.push_back(P[j][i]);
		}
		sort(arr.begin(), arr.end());
		F[i] = arr[mid];
	}
	ll sum = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			sum += abs(F[j] - P[i][j]);
		}
	}
	cout << sum << "\n";
	for (int i = 0; i < N; i++) {
		cout << F[i] << " ";
	}
}