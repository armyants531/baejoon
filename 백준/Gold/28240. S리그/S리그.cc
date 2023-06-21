// S리그  // geometry  // 해 구성하기
// 에디토리얼 참고
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int K, L, C, J;
	cin >> K >> L >> C >> J;
	for (int i = 1; i < n; i++) {
		cout << i << " ";
		if (i == K || i == L) {
			cout << 2 << "\n";
		}
		else if (i == C || i == J) {
			cout << 0 << "\n";
		}
		else {
			cout << 1 << "\n";
		}
	}
	// 마지막과 첫 번째 연결 가능해야 함 -> 매우 큰 y좌표 설정
	if (n == C || n == J) {
		cout << n << " " << -1000000000 << "\n";
	}
	else {
		cout << n << " " << 1000000000 << "\n";
	}
	return 0;
}