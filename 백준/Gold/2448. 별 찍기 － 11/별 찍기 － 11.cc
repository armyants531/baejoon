// 별 찍기 - 11  // 재귀
#include <iostream>
#include <cmath>

using namespace std;

int star_arr[3072][6143] = { 0, }; // 3 x 2 ^ 10 = 3072, 3072 * 2 - 1 = 6143
// 별 그리는 재귀 함수
void drawStars(int y, int x, int N) { // (y, x): 시어핀스키 삼각형 중심의 좌표, N: 삼각형의 높이
	if (N == 3) {
		// 기본 단위 그리기
		star_arr[y - 1][x] = 1;
		star_arr[y][x - 1] = 1;
		star_arr[y][x + 1] = 1;
		for (int i = 0; i < 5; i++) {
			star_arr[y + 1][x - 2 + i] = 1;
		}
		return;
	}
	else {
		int len = N / 2;
		drawStars(y, x, len);
		drawStars(y + len, x - len, len); // 왼쪽 아래 그리기
		drawStars(y + len, x + len, len); // 오른쪽 아래 그리기
	}
}

int main() {
	int N;
	cin >> N;
	drawStars(1, N - 1, N); // (y, x) = (1, N-1)에서 시작

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			if (star_arr[i][j] == 1) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << "\n";
	}
	return 0;
}