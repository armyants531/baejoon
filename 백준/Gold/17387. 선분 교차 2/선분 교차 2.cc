#include <iostream>
#include <cmath> // abs 함수 이용 

using namespace std;
// CCW(counter clockwise)
// 세 점이 일직선 위에 있는 경우 O
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
	else // 일직선 상에 있을 때
		return 0;
}

// 좌표 평면에서 거리의 대소관계를 간단히 비교할 수 있는 함수 만듦
long long distance(coord A, coord B) {
	long long len = abs(A.x - B.x) + abs(A.y - B.y);

	return len;
}

int main() {
	coord A, B, C, D;
	cin >> A.x >> A.y >> B.x >> B.y;
	cin >> C.x >> C.y >> D.x >> D.y;
	int ABC = CCW(A, B, C);
	int ABD = CCW(A, B, D);
	int CDA = CCW(C, D, A);
	int CDB = CCW(C, D, B);
	// AB를 기준으로 점 C, D의 CCW 확인
	int sign1 = ABC * ABD;
	// CD를 기준으로 점 A, B의 CCW 확인
	int sign2 = CDA * CDB;

	if (sign1 == 0 && sign2 == 0) { // 네 점이 일직선 상에 있거나 두 선분의 한 끝이 붙은 경우(ex: 'ㄱ'자 모양)				
		if ((((distance(A, B) < distance(A, C))) && (distance(A, B) < distance(A, D))) || (((distance(B, A) < distance(B, C))) && (distance(B, A) < distance(B, D)))) // 'A와 B의 거리 < A와 C의 거리'이고 'A와 B의 거리 < A와 D의 거리'또는
			cout << 0; // 'B와 A의 거리 < B와 C의 거리'이고 'B와 A의 거리 < B와 D의 거리'이면 교점이 없다
		else
			cout << 1; 
	}
	else {
		if (sign1 < 0 && sign2 < 0) // 어느 세 점도 일직선 상에 있지 않고, 교차하는 경우
			cout << 1;	
		else if ((sign1 == 0 && sign2 < 0) || (sign1 < 0 && sign2 == 0)) // 한 점을 제외한 세 점이 일직선 상에 있고 교차하는 경우(이 때 세 점은 서로 겹치지 않음)
			cout << 1;
		else
			cout << 0;
	}

	return 0;
}