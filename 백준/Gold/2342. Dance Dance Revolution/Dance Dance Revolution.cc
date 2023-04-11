// Dance Dance Revolution  // DP  // recursion
// 현재 위치부터 마지막 이동까지 드는 힘 = min(왼발로 이동할 때 드는 힘, 오른발로 이동할 때 드는 힘)
#include <bits/stdc++.h>

using namespace std;

int cost[5][5] = { {1, 2, 2, 2, 2}, {3, 1, 3, 4, 3}, {3, 3, 1, 3, 4}, {3, 4, 3, 1, 3}, {3, 3, 4, 3, 1} }; // cost[i][j] : 한 발을 i에서 j로 옮기는데 드는 힘
vector<int> arr;
int memo[5][5][100000] = { 0, };

int move(int l, int r, int idx) {
	if (idx == arr.size()) return 0;
	if (memo[l][r][idx] != 0) return memo[l][r][idx];
	return memo[l][r][idx] = min(cost[l][arr[idx]] + move(arr[idx], r, idx + 1), cost[r][arr[idx]] + move(l, arr[idx], idx + 1));
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	while (n != 0) {
		arr.push_back(n);
		cin >> n;
	}
	cout << move(0, 0, 0) << "\n";

	return 0;
}