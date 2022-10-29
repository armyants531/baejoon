#include <iostream>
#include <cmath> // abs 함수 이용
#include <algorithm> // max 함수 이용
#include <iomanip> // width 함수 이용

using namespace std;

int r1, c1, r2, c2;
int matrix[50][5] = { 0, };

int max_val = 1; // 잘린 소용돌이 행렬의 최댓값
int val = 1; // 잘리지 않은 소용돌이 행렬의 값
int start_list[5000] = { 0, }; // 소용돌이 한 겹의 시작점 리스트 생성

int main() {
	cin >> r1 >> c1 >> r2 >> c2;
	// 소용돌이 층의 개수
	int r = max(max(abs(r1), abs(c1)), max(abs(r2), abs(c2)));
	// fill out the center
	if (r1 <= 0 && 0 <= r2 && c1 <= 0 && 0 <= c2) {
		matrix[-r1][-c1] = 1;
	}
	for (int i = 0; i < r; i++) {
		// 소용돌이 한 겹의 시작점 지정
		int x = r + i;
		int y = r + 1 + i;
		if (i == 0) {
			val = 2;
			start_list[0] = val;
		}
		else {
			val = start_list[i - 1] + 8 * i;
			start_list[i] = val;
		}

		if (r + r1 <= x && x <= r + r2 && r + c1 <= y && y <= r + c2) {
			matrix[x - (r + r1)][y - (r + c1)] = val;
			max_val = val;
		}
		
		// 소용돌이 채워 넣기
		// fill up section
		for (int j = 0; j < 2 * i + 1; j++) {
			x -= 1;
			val += 1;
			if (r + r1 <= x && x <= r + r2 && r + c1 <= y && y <= r + c2) {
				matrix[x - (r + r1)][y - (r + c1)] = val;
				max_val = val;
			}
		}
		// fill left section
		for (int j = 0; j < 2 * i + 2; j++) {
			y -= 1;
			val += 1;
			if (r + r1 <= x && x <= r + r2 && r + c1 <= y && y <= r + c2) {
				matrix[x - (r + r1)][y - (r + c1)] = val;
				max_val = val;
			}
		}
		// fill down section
		for (int j = 0; j < 2 * i + 2; j++) {
			x += 1;
			val += 1;
			if (r + r1 <= x && x <= r + r2 && r + c1 <= y && y <= r + c2) {
				matrix[x - (r + r1)][y - (r + c1)] = val;
				max_val = val;
			}
		}
		// fill right section
		for (int j = 0; j < 2 * i + 2; j++) {
			y += 1;
			val += 1;
			if (r + r1 <= x && x <= r + r2 && r + c1 <= y && y <= r + c2) {
				matrix[x - (r + r1)][y - (r + c1)] = val;
				max_val = val;
			}
		}
	}
	// 정답 출력 코드
	int digit = floor(log10(max_val)) + 1;
	for (int i = 0; i < r2 - r1 + 1; i++) {
		for (int j = 0; j < c2 - c1 + 1; j++) {
			cout.width(digit);
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}