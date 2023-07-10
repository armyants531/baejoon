// 응애(HARD)  // 수학  // 조합론
// 응애 : 1, 인사x : 0
// 1번 후 : (a[i - 1] + a[i + 1]) % 2, 2^k번 후 : (a[i - 2^k] + a[i + 2^k]) % 2
// 2^k번 후 시계방향으로 2^k 만큼 회전한다고 생각하면 a[i + 2^k - 2^k] ^ a[i + 2^k + 2^k] = a[i] ^ a[i + 2 * 2^k]
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N, M, K;
	cin >> N >> M >> K;
	vector<ll> a(N);
	ll num;
	for (ll i = 0; i < M; i++) {
		cin >> num;
		a[num] = 1;
	}
	for (ll v = 1; v <= K; v <<= 1) { // 왼쪽으로 한 칸씩 shift, v = 2^k
		if ((K & v) == 0) continue; 
		vector<ll> b = a; // 임시 배열
		for (ll i = 0; i < N; i++) {
			if (a[i]) b[(i + 2 * v) % N] ^= a[i];
		}
		a = b;
	}
	ll cnt = 0;
	// K번 이후 상태
	for (ll i = 0; i < N; i++) {
		cnt += a[i];
	}
	cout << cnt << "\n";

	return 0;
}