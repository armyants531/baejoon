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

int sign(long long n) {
	// n의 부호 정보 표현(+이면 1, -이면 -1, 0이면 0)
	if (n > 0)
		return 1;
	else if (n < 0)
		return -1;
	else
		return 0;
}

// 평행한 두 벡터의 방향이 반대인지 알려주는 함수(AB 벡터와 AC 벡터)
bool isOpp(coord A, coord B, coord C) {
	// 각 성분의 부호 정보 표현(+이면 1, -이면 -1)
	coord AB, AC;
	AB.x = sign(B.x - A.x);
	AB.y = sign(B.y - B.y);
	AC.x = sign(C.x - A.x);
	AC.y = sign(C.y - A.y);
	
	if (AB.x == 0) { // 이때는 y성분을 비교
		if (AB.y == AC.y) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if (AB.x == AC.x) {
			return false;
		}
		else {
			return true;
		}
	}
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

	if (sign1 == 0 && sign2 == 0) { // 네 점이 일직선 상에 있거나 평행하지 않은 두 선분의 한 끝이 붙은 경우(ex: 'ㄱ'자 모양)				
		if ((((distance(A, B) < distance(A, C))) && (distance(A, B) < distance(A, D))) || (((distance(B, A) < distance(B, C))) && (distance(B, A) < distance(B, D)))) // 'A와 B의 거리 < A와 C의 거리'이고 'A와 B의 거리 < A와 D의 거리'또는
			cout << 0 << "\n"; // 'B와 A의 거리 < B와 C의 거리'이고 'B와 A의 거리 < B와 D의 거리'이면 교점이 없다
		else {
			cout << 1 << "\n";
			if (ABC != 0 || ABD != 0 || CDA != 0 || CDB != 0) { // 평행하지 않은 두 선분의 한 끝이 붙어있는 경우(ex: 'ㄱ'자 모양)
				if ((A.x == C.x && A.y == C.y) || (A.x == D.x && A.y == D.y)) { // A와 C 또는 D가 같은 점인 경우
					cout << A.x << " " << A.y << "\n";
				}

				else if ((B.x == C.x && B.y == C.y) || (B.x == D.x && B.y == D.y)) { // B와 C 또는 D가 같은 점인 경우
					cout << B.x << " " << B.y << "\n";
				}
			} 
			else { // 네 점이 일직선 상에 있을 때
				if (A.x == C.x && A.y == C.y) { // A와 C가 같은 점인 경우
					if (isOpp(A, B, D)) { // AB벡터와 AD벡터의 방향이 반대이면 교점은 하나
						cout << A.x << " " << A.y << "\n";
					}
				}
				else if (A.x == D.x && A.y == D.y) { // A와 D가 같은 점인 경우
					if (isOpp(A, B, C)) { // AB벡터와 AC벡터의 방향이 반대이면 교점은 하나
						cout << B.x << " " << B.y << "\n";
					}
				}
				else if (B.x == C.x && B.y == C.y) { // B와 C가 같은 점인 경우
					if (isOpp(B, A, D)) { // BA벡터와 BD벡터의 방향이 반대이면 교점은 하나
						cout << B.x << " " << B.y << "\n";
					}
				}
				else if (B.x == D.x && B.y == D.y) { // B와 D가 같은 점인 경우
					if (isOpp(B, A, C)) { // BA벡터와 BC벡터의 방향이 반대이면 교점은 하나
						cout << B.x << " " << B.y << "\n";
					}
				}
			}
		}	
	}
	else {
		if (sign1 < 0 && sign2 < 0) { // 어느 세 점도 일직선 상에 있지 않고, 교차하는 경우
			cout << 1 << "\n";
			// 두 점 (x1, y1), (x2, y2)를 지나는 직선의 방정식은 (x2 - x1)(y - y1) = (y2 - y1)(x - x1) (단, x1 != x2)
			// 두 개의 직선의 방정식을 연립하여 교점의 좌표 구함
			cout << fixed;
			cout.precision(16);
			double denominator = (A.x - B.x) * (C.y - D.y) - (A.y - B.y) * (C.x - D.x);
			double numerator_x = (A.x * B.y - A.y * B.x) * (C.x - D.x) - (A.x - B.x) * (C.x * D.y - C.y * D.x);
			double numerator_y = (A.x * B.y - A.y * B.x) * (C.y - D.y) - (A.y - B.y) * (C.x * D.y - C.y * D.x);
			double x = numerator_x / denominator;
			double y = numerator_y / denominator; // A.x = B.x 또는 C.x = D.x인 경우에도 성립함
			cout << x << " " << y << "\n";
		}
		else if ((sign1 == 0 && sign2 < 0) || (sign1 < 0 && sign2 == 0)) { // 한 점을 제외한 세 점이 일직선 상에 있고 교차하는 경우(이 때 세 점은 서로 겹치지 않음)
			cout << 1 << "\n";
			cout << fixed;
			cout.precision(16);
			double denominator = (A.x - B.x) * (C.y - D.y) - (A.y - B.y) * (C.x - D.x);
			double numerator_x = (A.x * B.y - A.y * B.x) * (C.x - D.x) - (A.x - B.x) * (C.x * D.y - C.y * D.x);
			double numerator_y = (A.x * B.y - A.y * B.x) * (C.y - D.y) - (A.y - B.y) * (C.x * D.y - C.y * D.x);
			double x = numerator_x / denominator;
			double y = numerator_y / denominator; // A.x = B.x 또는 C.x = D.x인 경우에도 성립함
			cout << x << " " << y << "\n";
		}
		else
			cout << 0 << "\n";
	}

	return 0;
}