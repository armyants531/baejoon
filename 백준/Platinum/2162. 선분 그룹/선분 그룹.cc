// 선분 그룹  // CCW  // Disjoint Set(Union-Find)
#include <bits/stdc++.h>

using namespace std;

// CCW(counter clockwise)
// 세 점이 일직선 위에 있는 경우 O
struct coord { //coordinate
	long long x;
	long long y;
};

// 선분 배열 선언
vector<pair<coord, coord>> line_arr;
// 선분의 부모 배열 선언(선분에 0~N-1의 번호를 붙이고, 분리 집합의 번호를 매김)
vector<int> parent;
// line_cnt[i] = 부모 노드가 i인 그룹에 속한 선분의 개수
vector<int> line_cnt(3000, 0);

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
// 네 점이 일직선 상에 있거나 두 선분의 한 끝이 붙은 경우(ex: 'ㄱ'자 모양)에 사용되는 특수한 함수임(보통의 거리 비교 시 사용하면 틀림)
long long distance(coord A, coord B) {
	long long len = abs(A.x - B.x) + abs(A.y - B.y);
	return len;
}

// Union-Find Alg
// get parent node of x
int get_parent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = get_parent(parent[x]);
}

// merge each parent node
void union_parent(int A, int B) {
	A = get_parent(A);
	B = get_parent(B);
	if (A < B)
		parent[B] = A;
	else
		parent[A] = B;
}

int areIntersect(pair<coord, coord> line1, pair<coord, coord> line2) {
	coord A, B, C, D;
	A = line1.first;
	B = line1.second;
	C = line2.first;
	D = line2.second;
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
			return 0; // 'B와 A의 거리 < B와 C의 거리'이고 'B와 A의 거리 < B와 D의 거리'이면 교점이 없다
		else
			return 1;
	}
	else {
		if (sign1 < 0 && sign2 < 0) // 어느 세 점도 일직선 상에 있지 않고, 교차하는 경우
			return 1;
		else if ((sign1 == 0 && sign2 < 0) || (sign1 < 0 && sign2 == 0)) // 한 점을 제외한 세 점이 일직선 상에 있고 교차하는 경우(이 때 세 점은 서로 겹치지 않음)
			return 1;
		else
			return 0;
	}
}

int main() {
	int N;
	cin >> N;
	pair<coord, coord> line;
	// 선분 정보 입력
	for (int i = 0; i < N; i++) {
		cin >> line.first.x >> line.first.y >> line.second.x >> line.second.y;
		line_arr.push_back(line);
		parent.push_back(i); // 처음에는 자기 자신을 parent로 설정
	}
	// 정순으로 parent 갱신
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (areIntersect(line_arr[i], line_arr[j])) { // 두 선분이 서로 교차하면
				union_parent(i, j); // parent를 합쳐줌
			}
		}
	}
	// 역순으로 parent 갱신
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (areIntersect(line_arr[i], line_arr[j])) { // 두 선분이 서로 교차하면
				union_parent(i, j); // parent를 합쳐줌
			}
		}
	}
	
	// 그룹별 선분 개수 세기
	int num_of_group = 0;
	for (int i = 0; i < N; i++) {
		line_cnt[parent[i]]++; 
	}
	// 그룹의 수 세기 & 가장 크기가 큰 그룹에 속한 선분의 개수 구하기
	int cnt = 0;
	int max_num = 0;
	for (int i = 0; i < N; i++) {
		int numOfLine = line_cnt[i];
		if (numOfLine != 0) {
			cnt++;
			if (max_num < numOfLine) {
				max_num = numOfLine;
			}
		}
	}
	cout << cnt << "\n" << max_num << "\n";
	
	return 0;
}