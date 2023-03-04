#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<vector<string>> table(9, vector<string>(9));
	vector<vector<string>> arr(9, vector<string>(9));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			string s;
			cin >> s;
			table[i][j] = s;
		}
	}
	arr[1] = { table[1][1], table[0][0], table[0][1], table[0][2], table[1][2], table[2][2], table[2][1], table[2][0], table[1][0] };
	arr[2] = { table[1][4], table[0][3], table[0][4], table[0][5], table[1][5], table[2][5], table[2][4], table[2][3], table[1][3] };
	arr[3] = { table[1][7], table[0][6], table[0][7], table[0][8], table[1][8], table[2][8], table[2][7], table[2][6], table[1][6] };
	arr[4] = { table[4][7], table[3][6], table[3][7], table[3][8], table[4][8], table[5][8], table[5][7], table[5][6], table[4][6] };
	arr[5] = { table[7][7], table[6][6], table[6][7], table[6][8], table[7][8], table[8][8], table[8][7], table[8][6], table[7][6] };
	arr[6] = { table[7][4], table[6][3], table[6][4], table[6][5], table[7][5], table[8][5], table[8][4], table[8][3], table[7][3] };
	arr[7] = { table[7][1], table[6][0], table[6][1], table[6][2], table[7][2], table[8][2], table[8][1], table[8][0], table[7][0] };
	arr[8] = { table[4][1], table[3][0], table[3][1], table[3][2], table[4][2], table[5][2], table[5][1], table[5][0], table[4][0] };
	sort(arr.begin() + 1, arr.end());
	for (int i = 1; i <= 8; i++) {
		cout << "#" << i << ". " << arr[i][0] << "\n";
		sort(arr[i].begin() + 1, arr[i].end());
		for (int j = 1; j < 9; j++) {
			cout << "#" << i << "-" << j << ". " << arr[i][j] << "\n";
		}
	}
}