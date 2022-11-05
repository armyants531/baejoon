// CCW  // 기하학
#include <iostream>

using namespace std;

struct coord { //coordinate
	long long x;
	long long y;
};

int ccw(coord P1, coord P2, coord P3) {
	long long val = P2.x * P3.y - P1.x * P3.y + P1.x * P2.y - P3.x * P2.y + P3.x * P1.y - P2.x * P1.y;
	if (val > 0) // 반시계
		return 1;
	else if (val < 0) // 시계
		return -1;
	else // 일직선
		return 0;
}

int main() {
	coord P1, P2, P3;
	cin >> P1.x >> P1.y;
	cin >> P2.x >> P2.y;
	cin >> P3.x >> P3.y;

	cout << ccw(P1, P2, P3) << "\n";

	return 0;
}