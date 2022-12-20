// K번째 수  // 이분 탐색  // 매개변수 탐색
// B[k] 보다 작거나 같은 숫자의 개수(cnt)가 k개 보다 작으면 안됨
// cnt == k 인 경우에 mid는 배열 A에 존재하지 않는 수일 수도 있기 때문에 high를 갱신해주어야 함
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N, k;

ll check(ll mid) { // mid 보다 작거나 같은 수를 세기
	ll cnt = 0;
	for (ll i = 1; i <= N; i++) { // 각 행에 대하여
		cnt += min(mid / i, N);
	}
	return cnt;
}

ll bSearch(ll low, ll high) {
	ll ans;
	while (low <= high) {
		ll mid = (low + high) / 2;
		ll cnt = check(mid);
		if (cnt >= k) { // mid 보다 작거나 같은 수가 k개 이상이면
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> k;
	cout << bSearch(1, N * N) << "\n";

	return 0;
}