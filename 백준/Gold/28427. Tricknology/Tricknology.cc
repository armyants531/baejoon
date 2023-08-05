// Tricknology  // 정수론  // 에라토스테네스의 체  // 누적합
// (x, x + 1) 쌍만 보면 됨 -> 소수가 될 가능성 있음(그 외는 불가능)
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
vector<int> a(500001); // 소수 개수의 누적합
vector<int> b(1000001); // 에라토스테네스의 체
vector<int> prime;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Q;
	cin >> Q;
	for (int i = 2; i <= 1000000; i++) {
		b[i] = i;
	}
	int sqr = 1000;
	for (int i = 2; i <= sqr; i++) {
		if (b[i] == 0) {
			continue;
		}
		for (int j = i * i; j <= 1000000; j += i) {
			b[j] = 0;
		}
	}
	// 소수 개수의 누적합 구하기
	for (int i = 2; i <= 500000; i++) {
		a[i] = a[i - 1];
		if (b[2 * i - 1]) {
			a[i]++;
		}
	}
	while (Q--) {
		int L, R;
		cin >> L >> R;
		int ans = a[R] - a[L];
		cout << ans << "\n";
	}
	return 0;
}