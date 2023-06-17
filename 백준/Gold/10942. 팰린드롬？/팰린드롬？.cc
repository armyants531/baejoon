// 팰린드롬?  // dp  // tabulation
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool table[2000][2000];

void tabulation(vector<int> arr, int n) {
	// 크기 1
	for (int i = 0; i < n; i++) {
		table[i][i] = true;
	}
	// 크기 2
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			table[i][i + 1] = true;
		}
	}
	// 크기 3이상
	for (int k = 2; k < n; k++) { // 크기 3~n
		for (int i = 0; i + k < n; i++) {
			if (arr[i] == arr[i+k] && table[i + 1][i + k - 1]) {
				table[i][i + k] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	tabulation(arr, N);
	int M;
	cin >> M;
	int S, E;
	for (int i = 0; i < M; i++) {
		cin >> S >> E;
		cout << table[S - 1][E - 1] << "\n";
	}
	return 0;
}