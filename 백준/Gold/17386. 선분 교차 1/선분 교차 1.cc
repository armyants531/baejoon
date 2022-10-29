#include <iostream>

using namespace std;
// CCW(counter clockwise)
// 세 점이 일직선 위에 있는 경우 x
struct coord { //coordinate
	long long x;
	long long y;
};

int CCW(coord A, coord B, coord C) {
	// overflow prevention
	// (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
	long long val = B.x * C.y - B.x * A.y - A.x * C.y - B.y * C.x + A.x * B.y + A.y * C.x;
	if (val > 0)
		return 1;
	else if (val < 0)
		return -1;
	else
		return 0;
}

int main() {
	coord A, B, C, D;
	cin >> A.x >> A.y >> B.x >> B.y;
	cin >> C.x >> C.y >> D.x >> D.y;

	// AB를 기준으로 점 C, D의 CCW 확인
	int sign1 = CCW(A, B, C) * CCW(A, B, D);
	// CD를 기준으로 점 A, B의 CCW 확인
	int sign2 = CCW(C, D, A) * CCW(C, D, B);
	if (sign1 == -1 && sign2 == -1) { 
		cout << 1;
	}
	else {
		cout << 0;
	}
}