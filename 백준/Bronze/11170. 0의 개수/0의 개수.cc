// 0의 개수  // 수학
#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, M, cnt = 0; // 0의 개수
		cin >> N >> M;
		for (int j = N; j <= M; j++) {
			// 숫자를 문자열로 변환
			string str = to_string(j);
			int len = str.length();
			for (int k = 0; k < len; k++) {
				if (str[k] == '0') {
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}