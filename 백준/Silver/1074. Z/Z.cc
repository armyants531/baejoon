#include <iostream>
#include <cmath>

using namespace std;

int N, r, c, cnt = 0;
// y, x: 탐색 중인 사분면의 가장 왼쪽 위 좌표
// size: 탐색 중인 사분면의 크기
void sol(int y, int x, int size) {
	// 종료
	if (y == r && x == c) {
		cout << cnt << "\n";
		return;
	}
	// 현재 사분면 내에 존재하면
	else if ((r < y + size && r >= y) && (c < x + size && c >= x)) {
		sol(y, x, size / 2);
		sol(y, x + size / 2, size / 2);
		sol(y + size / 2, x, size / 2);
		sol(y + size / 2, x + size / 2, size / 2);
	} 
	else { // 다음 사분면 탐색
		cnt += size * size;
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;
	int size = pow(2, N); // (1 << N)
	sol(0, 0, size);

	return 0;
}