#include <iostream>

using namespace std;

int map[500][500];

int main() {
	int N, M, B;
	cin >> N >> M >> B;
	int minTime = 256*500*500*2;
	int height;
	int maxH = 0;
	int minH = 256;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] > maxH)
				maxH = map[i][j];
			if (map[i][j] < minH)
				minH = map[i][j];
		}
	}
	for (int h = maxH; h >= minH; h--) { // 높이 h로 맞추기
		int t = 0;
		int block = B;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] > h) { // 더 높으면
					int diff = map[i][j] - h;
					t += diff * 2;
					block += diff;
				} 
				else if (map[i][j] < h) { // 더 낮으면
					int diff = h - map[i][j];
					t += diff;
					block -= diff;
				}
			}
		}
		if (minTime > t && block >= 0) {
			minTime = t;
			height = h;
		}
	}
	cout << minTime << " " << height << "\n";
	
	return 0;
}