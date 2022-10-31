#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	long long arr[100];
	
	cin >> arr[0];
	int xor_sum = arr[0];
	bool all_one = true; // 모두 1인지 확인 
	if (arr[0] != 1) {
		all_one = false; 
	}
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		xor_sum ^= arr[i];
		if (arr[i] != 1)
			all_one = false;
	}
	if (all_one) { // 모든 돌더미에 돌이 하나인 경우에는 돌더미가 짝수(Nim-sum이 0)이면 선공이 이기고, 홀수이면 후공이 이긴다. 
		if (xor_sum == 0)
			cout << "koosaga" << "\n";
		else
			cout << "cubelover" << "\n";
	}
	else { // 그 이외에는 Nim-sum이 0이 아니면 선공이 이기고, 0이면 후공이 이긴다.
		if (xor_sum == 0)
			cout << "cubelover" << "\n";
		else
			cout << "koosaga" << "\n";
	}
	return 0;
}