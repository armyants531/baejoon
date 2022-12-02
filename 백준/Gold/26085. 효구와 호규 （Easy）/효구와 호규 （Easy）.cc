// 효구와 호규 (Easy)  // 애드 혹
#include <bits/stdc++.h>

using namespace std;

int N, M;

bool ifAdj(vector<vector<int>> arr) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			if (arr[i][j] == arr[i][j + 1] || arr[i][j] == arr[i + 1][j] || arr[i + 1][j + 1] == arr[i][j + 1] || arr[i + 1][j + 1] == arr[i + 1][j]) { // 인접한 두 카드가 같은 경우
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int cnt0 = 0;
	int cnt1 = 0;
	vector<vector<int>> arr(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int val;
			cin >> val;
			arr[i].push_back(val);
			if (val == 0)
				cnt0++;
			else
				cnt1++;
		}
	}
	
	if ((cnt0 % 2) == 0 && (cnt1 % 2) == 0 && ifAdj(arr)) {
		cout << 1 << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}