// 소수 찾기  // math  // number theory  // Sieve of Eratosthenes
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(1001, 0);
	for (int i = 2; i < 1001; i++) {
		arr[i] = i;
	}
	// 2부터 시작하여 소수의 배수(2배수, 3배수,...)에 해당하는 수를 모두 지움(이미 지워진 경우 제외)
	for (int i = 2; i < 1001; i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = i * 2; j < 1001; j += i) {
			arr[j] = 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (arr[num] != 0) {
			cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;
}