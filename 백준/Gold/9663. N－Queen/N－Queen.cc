// N-Queen  // backtracking 
// https://chanhuiseok.github.io/posts/baek-1/ 참고
// 같은 열에는 하나의 퀸만 배치할 수 있으므로 퀸이 몇 행에 위치해 있는 지를 일차원 배열에 저장하고
// 현재의 다음 열에 퀸을 배치할 수 없으면 이전으로 돌아간다.
#include <bits/stdc++.h>

using namespace std;

vector<int> arr(14); // 0열 부터 시작(0~13) // 퀸들의 행 정보 담고 있음
int N; // size
int cnt = 0; // 경우의 수

// i번째 행, col번째 열에 퀸을 배치하고 유망성 판단
bool promising(int col) {
	// 다른 퀸들과 다른 행에 있어야 하고 대각선상(열번호 차이 == 행번호 차이)에 있으면 안된다
	for (int i = 0; i < col; i++) {
		if (arr[i] == arr[col]) {
			return false;
		}
		if (abs(col - i) == abs(arr[col] - arr[i])) {
			return false;
		}
	}
	return true;
}

// N-Queen Alg
void n_queen(int col) {
	// end point
	if (col > N - 1) {
		cnt++; // 경우의 수 증가
		return;
	}
	for (int i = 0; i < N; i++) {
		arr[col] = i; // i행, col열에 퀸 배치
		// 유망성 판단
		if (promising(col))
			n_queen(col + 1); // 다음 열로 넘어감
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	if (N <= 3) { // 경우를 안 나누어도 됨(빠른 시행)
		if (N == 1)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	else { // 재귀함수 호출
		n_queen(0);
		cout << cnt << "\n";
	}

	return 0;
}