// 책 페이지  // 수학
// https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1019 참고
#include <iostream>
#include <cmath> // pow

using namespace std;

int arr[10] = {0, };

// n을 구성하는 숫자 세서 배열에 저장하는 함수
void numOf(int n, int pow) { 
	while (n) {
		arr[n % 10] += pow;
		n /= 10;
	}
}

int main() {
	int N;
	cin >> N;

	bool repeat = true;
	int repeat_cnt = 0; // while문 반복 횟수
	while (repeat) {
		if (N <= 9) {
			// A(= 1)부터 B(= N)까지 각 숫자 개수 센 후 더해주기
			for (int i = 1; i <= N; i++) {
				arr[i] += pow(10, repeat_cnt);
			}
			repeat = false; // end point 
		}
		else { // N >= 20
			// A: 1을 10으로 바꾸어 주는 작업과 같은 작업(A는 항상 1임)
			for (int i = 1; i <= 9; i++) {
				arr[i] += pow(10, repeat_cnt);
			}
			// B = N: N을 1씩 줄여가면서 일의 자리 수를 9로 맞추어 줌
			while (true) {
				if (N % 10 == 9)
					break;
				else {
					int power = pow(10, repeat_cnt);
					numOf(N, power);
					N--;
				}
			}
			// A부터 B까지 일의 자리 0~9가 (B/10 - A/10 + 1) * pow(10, repeat_cnt)번 사용됨(A = 10)
			for (int i = 0; i <= 9; i++) {
				int val = N / 10;
				arr[i] += val * (int) pow(10, repeat_cnt);
			}
			repeat_cnt++;
			N /= 10; // N 값 변경 
		}
	}
	// 출력
	for (int i = 0; i <= 9; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	return 0;
}