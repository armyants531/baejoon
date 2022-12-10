// 중복 없는 님 게임  // 스프라그–그런디 정리
// 그런디 수 g(n): g(0) = 0, g(1) = 1, g(2) = 1, g(3) = 2, g(4) = 2, g(5) = 2, g(6) = 3,...
// g(x) = n(where n(n+1)/2 <= x < (n+1)(n+2)/2) 
// g(x) = floor((-1 + sqrt(1 + 8 * x)) / 2)
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> Grundy_num;
	// 그런디 수 저장
	for (int i = 0; i <= 60; i++) {
		int val = floor((-1 + sqrt(1 + 8 * i)) / 2);
		// cout << val << "\n";
		Grundy_num.push_back(val);
	}
	int N;
	int xor_sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		xor_sum ^= Grundy_num[num];
	}
	if (xor_sum == 0) {
		cout << "cubelover" << "\n";
	}
	else {
		cout << "koosaga" << "\n";
	}

	return 0;
}