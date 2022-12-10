// Nim  // game theory  // Sprague-Grundy Theorem
// 각 시행 당 O(n)
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	while (n) {
		int xorNum = 0;
		int arr[1000] = { 0, };
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			// xor 취하기
			xorNum = xorNum ^ arr[i];
		}
		int win_num = 0;
		// 평형 상태 도달 방법 수 구하기
		for (int i = 0; i < n; i++) {
			// i번째 돌 더미를 제외하고 xor 계산 (xorNum ^ arr[i])
			// i번 째 돌 더미의 돌 개수(arr[i])를 줄이고 xor 후 0이 될 수 있는가?
			if (arr[i] > (xorNum ^ arr[i])) { // 돌 더미의 돌 개수가 더 크면 가능 
				win_num++;
			}
		}
		cout << win_num << "\n";
		cin >> n;
	}

	return 0;
}