#include <iostream>
#include <string>
#include <vector>
#include <cmath> // abs
#include <algorithm> // min

using namespace std;

vector<bool> malfuc(10, false);

bool check(int n) { // 숫자 키로 n을 누를 수 있는지 확인
	if (n < 0) { // 음수 채널 입력 불가
		return false;
	}
	else {
		string str = to_string(n);
		for (int i = 0; i < str.length(); i++) {
			if (malfuc[str[i] - '0']) { // 오작동 키가 n에 포함되어 있으면
				return false;
			}
		}
	}
	return true;
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;

	int temp;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		malfuc[temp] = true;
	}

	int min_cnt = abs(n - 100);
	string str = to_string(n);
	if (min_cnt != 0) {
		string str_i;
		for (int i = 0; i < 499900; i++) { // N의 최댓값이 500,000이므로 i < 499900까지
			// 아래에서 n-i를 먼저 확인하는 이유: n-i의 자리수가 n+i의 자리수보다 작은 경우가 존재하기 때문!
			if (check(n - i)) { // 숫자 키로 n - i를 입력 가능하면
				str_i = to_string(n - i);
				int len = str_i.length();
				min_cnt = min(len + i, min_cnt);
				break; // 최솟값 구했으므로 종료
			}
			else if (check(n + i)) { // 숫자 키로 n + i를 입력 가능하면  
				str_i = to_string(n + i);
				int len = str_i.length();
				min_cnt = min(len + i, min_cnt);
				break; // 최솟값 구했으므로 종료
			}
		}
	}

	cout << min_cnt << "\n";

	return 0;
}