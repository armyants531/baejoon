#include <iostream>

using namespace std;

typedef struct FISH {
	int y;
	int x;
	int dir; // direction
} fish;
// ↑, ↖, ←, ↙, ↓, ↘, →, ↗ 
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int max_sum = 0;

void solve(int shark_y, int shark_x, int sum, int board[][4], fish fish_arr[]) {
	// for back tracking, make copies of board and fish_arr 
	int copy_board[4][4];
	fish copy_fish_arr[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copy_board[i][j] = board[i][j];
		}
	}
	for (int i = 1; i < 17; i++) {
		copy_fish_arr[i] = fish_arr[i];
	}

	// eat fish
	int fish_num = copy_board[shark_y][shark_x];
	int shark_dir = copy_fish_arr[fish_num].dir;
	copy_fish_arr[fish_num] = { -1, -1, -1 }; // mark that fish was dead
	copy_board[shark_y][shark_x] = -1;

	sum += fish_num;
	if (sum > max_sum)
		max_sum = sum;

	// move fish
	for (int i = 1; i < 17; i++) {
		if (copy_fish_arr[i].dir == -1) { // if dead fish
			continue;
		}
		int cy = copy_fish_arr[i].y;
		int cx = copy_fish_arr[i].x;
		int cdir = copy_fish_arr[i].dir;

		int ny = cy + dy[cdir];
		int nx = cx + dx[cdir];
		int ndir = cdir;
		while (!(ny >= 0 && ny < 4 && nx >= 0 && nx < 4) || (ny == shark_y && nx == shark_x)) { // 범위 밖 또는 상어가 가려는 위치에 있으면
			ndir = (ndir + 1) % 8; // change direction
			ny = cy + dy[ndir];
			nx = cx + dx[ndir];
		}
		if (copy_board[ny][nx] == -1) { // if there is no fish on the location
			// changed the info of the current fish
			copy_fish_arr[i].y = ny;
			copy_fish_arr[i].x = nx;
			copy_fish_arr[i].dir = ndir;
			// change the number int the board
			copy_board[cy][cx] = -1;
			copy_board[ny][nx] = i;
		}
		else { // if there is a fish on the location
			int swap_num = copy_board[ny][nx];
			// changed the info of the swaped fish
			copy_fish_arr[swap_num].y = cy;
			copy_fish_arr[swap_num].x = cx;
			// changed the info of the current fish
			copy_fish_arr[i].y = ny;
			copy_fish_arr[i].x = nx;
			copy_fish_arr[i].dir = ndir;
			// change the number int the board
			copy_board[cy][cx] = swap_num;
			copy_board[ny][nx] = i;
		}
	}

	// move shark 
	for (int i = 1; i < 4; i++) { // move 1~3 block
		int ny = shark_y + dy[shark_dir] * i;
		int nx = shark_x + dx[shark_dir] * i;
		if (!(ny >= 0 && ny < 4 && nx >= 0 && nx < 4)) { // out of bound
			break;
		}
		else if (copy_board[ny][nx] != -1) { // not empty
			solve(ny, nx, sum, copy_board, copy_fish_arr);
		}
	}
}

int main() {
	fish fish_arr[17];
	int board[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b; // fish number, direction
			cin >> a >> b;
			b--;
			fish_arr[a] = { i, j, b };
			board[i][j] = a;
		}
	}
	max_sum = 0;
	solve(0, 0, 0, board, fish_arr);
	cout << max_sum << "\n";

	return 0;
}