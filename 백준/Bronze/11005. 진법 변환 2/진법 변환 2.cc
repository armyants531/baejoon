// 진법 변환 2
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string num = "";
	int N, B;
	cin >> N >> B;
	while (N) {
		int rem = N % B; // 나머지
		if (rem >= 10) {
			rem -= 10;
			rem += 'A';
		}
		else {
			rem += '0';
		}
		num += rem;
		N /= B;
	}
	reverse(num.begin(), num.end());

	cout << num << "\n";
}