#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<ll> remain(M); // 누적합의 나머지 저장
	ll pre_sum = 0;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		pre_sum += A;
		pre_sum %= M;
		remain[pre_sum]++;
	}
	ll cnt = remain[0];

	for (int i = 0; i < M; i++) {
		if (remain[i] == 0 || remain[i] == 1) {
			continue;
		}
		else {
			cnt += remain[i] * (remain[i] - 1) / 2;
		}
	}
	cout << cnt << "\n";

	return 0;
}