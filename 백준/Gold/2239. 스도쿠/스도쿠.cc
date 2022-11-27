// 스도쿠  // backtracking  // dfs
// https://kau-algorithm.tistory.com/233 참고
#include <bits/stdc++.h>

using namespace std;

vector<string> board(9);
vector<vector<bool>> col(9, vector<bool>(9, false));
vector<vector<bool>> row(9, vector<bool>(9, false));
vector<vector<bool>> square(9, vector<bool>(9, false));

void dfs(int cnt, int y, int x) {
	if (cnt == 81) { // end condition
		for (int i = 0; i < 9; i++) {
			cout << board[i] << "\n";
		}
		exit(0); // 프로그램 종료
	}
	
	if (board[y][x] == '0') {
		for (int i = 1; i <= 9; i++) {
			int sq_idx = (y / 3) * 3 + x / 3; 
			if (!col[x][i - 1] && !row[y][i - 1] && !square[sq_idx][i - 1]) {
				board[y][x] = i + '0';
				col[x][i - 1] = true;
				row[y][i - 1] = true;
				square[sq_idx][i - 1] = true;
				if (x + 1 == 9) {
					dfs(cnt + 1, y + 1, 0);
				}
				else {
					dfs(cnt + 1, y, x + 1);
				}
				board[y][x] = '0';
				col[x][i - 1] = false;
				row[y][i - 1] = false;
				square[sq_idx][i - 1] = false;
			}
		}
	}
	else { // 칸이 채워진 경우
		if (x + 1 == 9) {
			dfs(cnt + 1, y + 1, 0);
		}
		else {
			dfs(cnt + 1, y, x + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		string str;
		cin >> str;
		board[i] = str;
		for (int j = 0; j < 9; j++) {
			int n = str[j] - '0';
			if (n != 0) {
				col[j][n-1] = true;
				row[i][n-1] = true;
				int sq_idx = (i / 3) * 3 + j / 3;
				square[sq_idx][n-1] = true;
			}
		}
	}
	dfs(0, 0, 0);
	return 0;
}