// 행렬 곱셈 순서  // DP  // 최소행렬곱셈법
// A: 5 x 3, B: 3 x 2, C: 2 x 6일 때
// arr[N + 1] = {5, 3, 2, 6}
#include <bits/stdc++.h>

using namespace std;

int MAX = 2147483647;
vector<int> arr(501);
vector<vector<int>> table;

// memoization(top - down)
int MCM(int s, int e) {
	if (s == e) {
		return 0;
	}
	if (table[s][e] != 0) {
		return table[s][e];
	}
	table[s][e] = MAX;
	for (int k = s; k < e; k++) {
		table[s][e] = min(table[s][e], MCM(s, k) + MCM(k + 1, e) + arr[s - 1] * arr[k] * arr[e]);
	}
	// cout << "table[" << s << "][" << e << "] : " << table[s][e] << "\n";
	return table[s][e];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int r, c;
	table.resize(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < N - 1; i++) {
		cin >> r >> c;
		arr[i] = r;
	}
	cin >> r >> c;
	arr[N - 1] = r;
	arr[N] = c;
	cout << MCM(1, N) << "\n";

	return 0;
}