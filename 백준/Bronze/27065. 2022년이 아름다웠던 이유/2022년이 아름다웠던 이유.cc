// 2022년이 아름다웠던 이유  // 소수 판정
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
		int n;
		cin >> n;
		vector<int> arr;
		int sum0 = 0;
		for (int j = 1; j <= n - 1; j++) {
			if (n % j == 0) {
				arr.push_back(j);
				sum0 += j;
			}
		}
		if (sum0 > n) {
			bool isGood = true;
			for (int j = 0; j < arr.size(); j++) {
				int sum = 0;
				for (int k = 1; k <= arr[j] - 1; k++) {
					if (arr[j] % k == 0) {
						sum += k;
					}
				}
				if (sum > arr[j]) {
					isGood = false;
					break;
				}
			}
			if (isGood) {
				cout << "Good Bye" << "\n";
			}
			else {
				cout << "BOJ 2022" << "\n";
			}
		}
		else {
			cout << "BOJ 2022" << "\n";
		}
	}

	return 0;
}