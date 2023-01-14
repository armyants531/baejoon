// 한수  // 브루트포스
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	if (N <= 99) {
		cout << N << "\n";
	}
	else { // N >= 100
		int cnt = 99;
		for (int i = 100; i <= N; i++) {
			string num = to_string(i);
			bool isHan = true;
			int diff = (num[1] - '0') - (num[0] - '0');
			for (int j = num.size() - 1; j >= 2; j--) {
				int diff2 = (num[j] - '0') - (num[j - 1] - '0');
				if (diff2 != diff) {
					isHan = false;
					break;
				}
			}
			if (isHan) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}