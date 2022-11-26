// 2048 (Easy)  // bactracking  // dfs
// https://donggoolosori.github.io/2020/11/06/boj-12100/ 참고
#include <bits/stdc++.h>

using namespace std;

int N, ans = 2;
// 왼쪽으로 이동
vector<vector<int>> left(vector<vector<int>> board) {
	// 이미 합쳐진 상태인지 확인(한 번 움직일 때 마다 각 블록은 최대 1번 합칠 수 있기 때문)
	vector<vector<bool>> check_board(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) { // 0열은 움직이지 않음 -> 1부터 시작
			if (board[i][j] == 0) // 움직일 것이 없는 경우
				continue;
			for (int k = j - 1; k >= 0; k--) {
				if (board[i][k] == 0) { // 비어있는 경우
					board[i][k] = board[i][k + 1]; // 오른쪽 칸을 왼쪽으로 옮김
					board[i][k + 1] = 0;
				}
				else if (board[i][k] == board[i][k + 1] && !check_board[i][k]) { // 두 값이 같고, 합쳐지지 않았으면
					board[i][k] += board[i][k + 1];
					check_board[i][k] = true;
					board[i][k + 1] = 0;
					break;
				}
				else { // 이동, 합치기 불가
					break;
				}
			}
		}
	}
	return board;
}
// 오른쪽으로 이동
vector<vector<int>> right(vector<vector<int>> board) {
	vector<vector<bool>> check_board(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = N - 2; j >= 0; j--) { // N-1열은 움직이지 않음
			if (board[i][j] == 0) {
				continue;
			}
			for (int k = j + 1; k < N; k++) {
				if (board[i][k] == 0) {
					board[i][k] = board[i][k - 1];
					board[i][k - 1] = 0;
				}
				else if (board[i][k - 1] == board[i][k] && !check_board[i][k]) {
					board[i][k] += board[i][k - 1];
					check_board[i][k] = true;
					board[i][k - 1] = 0;
					break;
				}
				else { // 이동, 합치기 불가
					break;
				}
			}
		}
	}
	return board;
}
// 위로 이동
vector<vector<int>> up(vector<vector<int>> board) {
	vector<vector<bool>> check_board(N, vector<bool>(N, false));
	for (int j = 0; j < N; j++) {
		for (int i = 1; i < N; i++) { // 0행은 움직이지 않음
			if (board[i][j] == 0) {
				continue;
			}
			for (int k = i - 1; k >= 0; k--) {
				if (board[k][j] == 0) { // 이동 가능
					board[k][j] = board[k + 1][j];
					board[k + 1][j] = 0;
				}
				else if (board[k][j] == board[k + 1][j] && !check_board[k][j]) { // 합치기 가능
					board[k][j] += board[k + 1][j];
					check_board[k][j] = true;
					board[k + 1][j] = 0;
					break;
				}
				else { // 이동, 합치기 불가
					break;
				}
			}
		}
	}
	return board;
}
// 아래로 이동
vector<vector<int>> down(vector<vector<int>> board) {
	vector<vector<bool>> check_board(N, vector<bool>(N, false));
	for (int j = 0; j < N; j++) {
		for (int i = N - 2; i >= 0; i--) {
			if (board[i][j] == 0) {
				continue;
			}
			for (int k = i + 1; k < N; k++) {
				if (board[k][j] == 0) { // 이동 가능
					board[k][j] = board[k - 1][j];
					board[k - 1][j] = 0;
				}
				else if (board[k][j] == board[k - 1][j] && !check_board[k][j]) { // 합치기 가능
					board[k][j] += board[k - 1][j];
					check_board[k][j] = true;
					board[k - 1][j] = 0;
					break;
				}
				else { // 이동, 합치기 불가
					break;
				}
			}
		}
	}
	return board;
}

void dfs(int cnt, vector<vector<int>> board)
{
	if (cnt == 5) {
		int current_max = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				current_max = max(current_max, board[i][j]);
			}
		}
		ans = max(ans, current_max);
		return;
	}
	else {
		cnt++;
		dfs(cnt, left(board));
		dfs(cnt, right(board));
		dfs(cnt, up(board));
		dfs(cnt, down(board));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<vector<int>> board(21, vector<int>(21, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	dfs(0, board);
	cout << ans << "\n";

	return 0;
}