// 걷다보니 신천역 삼 (Large)  // 정수론  // DP
// N 자리 3의 배수의 수 = 3 ^ (N - 1) - 3 ^ (N - 2) = 2 * 3 ^(N - 2)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> table(33334); // table[i]: 3으로 나눈 나머지가 0인 i자리 숫자
ll p = 1000000009;

ll memo(int N) {
	if (N == 1) {
		return 0;
	}
	else if (N == 2) {
		return table[N] = 2;
	}
	else {
		return table[N] = 3 * memo(N - 1) % p;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	cout << memo(N) << "\n";

	return 0;
}
