// 라면 사기 (Small)  // greedy
// https://david0506.tistory.com/47 참고
// A[i]를 앞에서부터 차례로 소진시키기 O(N) 
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> A;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	int cost = 0;
	for (int i = 0; i <= N - 3; i++) {
		if (A[i + 1] > A[i + 2]) { 
			// 3개 짜리 구매를 위해 A[i + 1]과 A[i + 2]를 비슷하게 맞춰주는 작업
			int two = A[i + 1] - A[i + 2];
			two = min(A[i], two);
			A[i] -= two;
			A[i + 1] -= two;
			cost += two * 5;
			// 3개짜리 최대로 구입
			int three = min({ A[i], A[i+1], A[i + 2] });
			A[i] -= three;
			A[i + 1] -= three;
			A[i + 2] -= three;
			cost += three * 7;
			// A[i + 1] == 0이면 남은 A[i]처리
			if (A[i + 1] == 0) {
				cost += A[i] * 3;
				A[i] = 0;
			}
		}
		else if (A[i + 1] <= A[i + 2]) {
			// 3개짜리 최대한 구입
			int three = min({ A[i], A[i + 1], A[i + 2] });
			A[i] -= three;
			A[i + 1] -= three;
			A[i + 2] -= three;
			cost += three * 7;
			// 2개짜리로 A[i] 최대한 소진
			int two = min(A[i], A[i + 1]);
			A[i] -= two;
			A[i + 1] -= two;
			cost += two * 5;
			if (A[i] != 0) { // 1개 짜리로 A[i] 소진
				cost += A[i] * 3;
				A[i] = 0;
			}
		}
	}
	// 맨 마지막 2개 공장에서 구입
	int two = min(A[N - 2], A[N - 1]);
	A[N - 2] -= two;
	A[N - 1] -= two;
	cost += two * 5;
	cost += (A[N - 2] * 3 + A[N - 1] * 3);
	A[N - 2] = 0;
	A[N - 1] = 0;
	cout << cost << "\n";

	return 0;
}
