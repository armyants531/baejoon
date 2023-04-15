// 진법 변환
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string N;
	int B;
	int num = 0;
	cin >> N >> B;
	for (int i = 0; i < N.size(); i++) {
		int number = (int)(N[N.size() - 1 - i] - 'A');
		if (number >= 0) { // 10 이상
			number += 10;
		}
		else { // 9 이하
			number += 17;
		}
		//cout << number << "\n";
		num += number * pow(B, i);
	}
	cout << num << "\n";
}