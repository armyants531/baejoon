// GCD(n, k) = 1  // 오일러 파이 함수
// p1, p2,...,pn 이 m의 소인수일때 m 이하의 양의 정수 중 m과 서로소인 양의 정수의 개수
// PI(m) = m * (1 - 1/p1) * (1 - 1/p2) *...* (1 - 1/pn) 
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int M = N;
	int ans = M;
	for (int i = 2; i * i <= N; i++) {
		if (M % i == 0) {
			ans /= i;
			ans *= (i - 1);
		}
		while (M % i == 0) {
			M /= i;
		}
	}
	if (M != 1) {
		ans /= M; // overflow 막기 위해 나누기 먼저! 
		ans *= (M - 1);
	}
	cout << ans << "\n";
	
	return 0;
}