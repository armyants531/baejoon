// 경찰차  // dp
// https://injae-kim.github.io/problem_solving/2020/03/11/baekjoon-2618.html 참고
// 두 경찰차의 현재 위치 상태(인덱스)를 A, B, 다음 사건의 위치 상태(인덱스)를 C라 할 때 현 상태에서 나머지 사건을 해결할 때 최소 이동 거리의 합은 
// min_path(A, B) = min(min_path(A, C) + dist(B, C), min_path(C, B) + dist(A, C)); // min(B가 C로 가는 경우, A가 C로 가는 경우)
#include <bits/stdc++.h>

using namespace std;

struct point {
	int x;
	int y;
};

vector<vector<int>> dp(1001, vector<int>(1001));
vector<point> path_A;
vector<point> path_B;
int N, W;

// 현재 상태에서 두 경찰차가 이동해야 할 거리 중 최솟값 리턴
int memo(int A, int B) {
	if (A == W || B == W) { // 모든 사건 해결
		return 0;
	}
	if (dp[A][B] != 2000004) {
		return dp[A][B];
	}
	// next idx
	int C = 1 + max(A, B);
	int distBC = abs(path_B[C].x - path_B[B].x) + abs(path_B[C].y - path_B[B].y);
	int distAC = abs(path_A[C].x - path_A[A].x) + abs(path_A[C].y - path_A[A].y);
	dp[A][B] = min(memo(A, C) + distBC, memo(C, B) + distAC);
	return dp[A][B];
}

// 경찰차 번호 출력
void print_num(int A, int B) {
	if (A == W || B == W) { // 모든 사건 해결
		return;
	}
	// next idx
	int C = 1 + max(A, B);
	int distBC = abs(path_B[C].x - path_B[B].x) + abs(path_B[C].y - path_B[B].y);
	int distAC = abs(path_A[C].x - path_A[A].x) + abs(path_A[C].y - path_A[A].y);
	if (dp[A][C] + distBC < dp[C][B] + distAC) { // B가 이동하는 것이 효율적일 때
		cout << 2 << "\n";
		print_num(A, C);
	}
	else { // A가 이동하는 것이 효율적일 때
		cout << 1 << "\n";
		print_num(C, B);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> W;
	fill(dp.begin(), dp.end(), vector<int>(W + 1, 2000004));
	path_A.push_back({1, 1});
	path_B.push_back({N, N});
	int x, y;
	for (int i = 0; i < W; i++) {
		cin >> x >> y;
		path_A.push_back({ x, y });
		path_B.push_back({ x, y });
	}
	int dist = memo(0, 0);
	/*
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < W; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	cout << dist << "\n";
	print_num(0, 0);

	return 0;
}