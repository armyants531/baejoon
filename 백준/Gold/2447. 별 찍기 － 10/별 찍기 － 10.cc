#include <iostream>
#include <cmath>

using namespace std;

int star_arr[2187][2187] = {0, };

void drawStars(int y, int x, int N) { // y, x: 좌표, N: 정사각형 한 변의 길이
	if (N == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				star_arr[y + i][x + j] = 1;
			}
		}
		star_arr[y + 1][x + 1] = 0;
		
		return; // end point
	}
	else {
		int len = N / 3;
		drawStars(y, x, len);
		drawStars(y, x + len, len);
		drawStars(y, x + len * 2, len);
		drawStars(y + len, x, len);

		drawStars(y + len, x + len * 2, len);
		drawStars(y + len * 2, x, len);
		drawStars(y + len * 2, x + len, len);
		drawStars(y + len * 2, x + len * 2, len);
	}
}

int main() {
	int N;
	cin >> N;
	drawStars(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
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