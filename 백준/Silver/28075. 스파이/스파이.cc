#include <bits/stdc++.h> 

using namespace std;

vector<vector<int>> arr(2, vector<int>(3));
int N, M;
int ans = 0;

void dfs(int past_j, int cnt, int mission) {
	if (mission == N) {
		if (cnt >= M) {
			ans++;			
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (past_j == j) {
				dfs(j, cnt + arr[i][j] / 2, mission + 1);
			}
			else {
				dfs(j, cnt + arr[i][j], mission + 1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(-1, 0, 0);
	cout << ans << "\n";
}