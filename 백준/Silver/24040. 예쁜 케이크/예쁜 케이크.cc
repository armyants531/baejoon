// 예쁜 케이크  // 정수론
// 3으로 나눈 나머지가 2인 수, 9로 나누어 떨어지는 수
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		ll N;
		cin >> N;
		if (N % 3 == 2 || N % 9 == 0) {
			cout << "TAK" << "\n";
		}
		else {
			cout << "NIE" << "\n";
		}
	}

	return 0;
}