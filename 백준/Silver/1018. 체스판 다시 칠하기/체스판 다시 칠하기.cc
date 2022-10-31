#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string arr[50];
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int min_val = 64;
	int temp1 = 0; // 다시 칠해야 하는 개수(왼쪽 위를 W)
	int temp2 = 0; // 다시 칠해야 하는 개수(왼쪽 위를 B)
	// 체스판 왼쪽 위 좌표 (y, x)
	for (int y = 0; y <= N - 8; y++) {
		for (int x = 0; x <= M - 8; x++) {
			for (int a = y; a < y + 8; a++) {
				for (int b = x; b < x + 8; b++) {
					if ((a + b) % 2) {
						if (arr[a][b] == 'B') {
							temp1++;
						}
						else {
							temp2++;
						}
					}
					else {
						if (arr[a][b] == 'W') {
							temp1++;
						}
						else {
							temp2++;
						}
					}
				}
			}
			// 왼쪽 위 좌표 바꾸기 전 min값 갱신
			min_val = min(min_val, temp1);
			min_val = min(min_val, temp2);
			temp1 = 0; // 개수 초기화
			temp2 = 0; // 개수 초기화
		}
	}
	cout << min_val << "\n";

	return 0;
}