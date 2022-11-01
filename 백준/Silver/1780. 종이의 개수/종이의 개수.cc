#include <iostream>

using namespace std;

int paper[2187][2187];
int a_cnt = 0, b_cnt = 0, c_cnt = 0;

void sol(int y, int x, int size) {
	int color = paper[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (color != paper[i][j]) {
				sol(y, x, size / 3);
				sol(y, x + size / 3, size / 3);
				sol(y, x + size * 2 / 3, size / 3);
				sol(y + size / 3, x, size / 3);
				sol(y + size / 3, x + size / 3, size / 3);
				sol(y + size / 3, x + size * 2 / 3, size / 3);
				sol(y + size * 2 / 3, x, size / 3);
				sol(y + size * 2 / 3, x + size / 3, size / 3);
				sol(y + size * 2 / 3, x + size * 2 / 3, size / 3);
				return; // end
			}
		}
	}
	// 같은 숫자로 이루어진 종이 일때
	if (color == -1)
		a_cnt++;
	else if (color == 0)
		b_cnt++;
	else
		c_cnt++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	sol(0, 0, n);
	cout << a_cnt << "\n";
	cout << b_cnt << "\n";
	cout << c_cnt << "\n";
	return 0;
}