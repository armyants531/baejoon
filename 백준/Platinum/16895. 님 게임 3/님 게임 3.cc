#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int xorNum;
	int arr[1000] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// xor 취하기
	xorNum = arr[0];
	for (int i = 1; i < n; i++) {
		xorNum = xorNum ^ arr[i];
	}
	if (xorNum == 0) { // 모든 수를 xor을 취한 값이 0이면 패배
		cout << 0 << "\n";
	}
	else {
		int win_num = 0;
		// 평형 상태 도달 방법 수 구하기
		for (int i = 0; i < n; i++) {
			int xorResult = 0;
			// i번째 돌 더미를 제외하고 xor 계산
			for (int j = 0; j < n; j++) {
				if (i != j) {
					xorResult = xorResult ^ arr[j];
				}
			}
			// i번 째 돌 더미의 돌 개수를 1개씩 줄이고 xor 후 0인지 확인
			int i_num = arr[i];
			for (int j = 1; j <= i_num; j++) {
				if ((xorResult ^ (i_num - j)) == 0) {
					win_num++; // 이기는 방법 수 증가
				}
			}
		}
		cout << win_num << "\n";
	}
		
	return 0;
}
