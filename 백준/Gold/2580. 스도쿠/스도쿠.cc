// 스도쿠  // backtracking  // dfs
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board(9, vector<int>(9));
vector<vector<bool>> col(9, vector<bool>(9, false));
vector<vector<bool>> row(9, vector<bool>(9, false));
vector<vector<bool>> square(9, vector<bool>(9, false));

void dfs(int y, int x) {
	if (y == 9 && x == 0) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0); // 프로그램 종료
	}
	else if (board[y][x] == 0) { // 현재 칸이 비어있으면
		for (int i = 0; i <= 8; i++) {
			int square_idx = y / 3 * 3 + x / 3;
			if (!row[y][i] && !col[x][i] && !square[square_idx][i]) {
				row[y][i] = true;
				col[x][i] = true;
				square[square_idx][i] = true;
				board[y][x] = i + 1; // 빈 칸에 숫자 삽입
				if (x == 8) {
					dfs(y + 1, 0);
				}
				else {
					dfs(y, x + 1);
				}
				// backtracking
				row[y][i] = false;
				col[x][i] = false;
				square[square_idx][i] = false;
				board[y][x] = 0;
			}
		}
	}
	else { // 숫자가 채워져 있으면 
		if (x == 8) {
			dfs(y + 1, 0);
		}
		else {
			dfs(y, x + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				int idx = board[i][j] - 1;
				col[j][idx] = true; // 열 정보 수정
				row[i][idx] = true; // 행 정보 수정 
				int square_idx = i / 3 * 3 + j / 3;
				square[square_idx][idx] = true; // 9분면 정보 수정
			}
		}
	}
	dfs(0, 0);
	return 0;
}