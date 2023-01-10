// 라면 사기 (Large)  // greedy
// B > C이면 라면 사기 (Small)과 같은 문제
// B <= C이면 그냥 낱개로 구입
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	ll N, B, C;
	cin >> N >> B >> C;
	vector<ll> A;
	for (int i = 0; i < N; i++) {
		ll a;
		cin >> a;
		A.push_back(a);
	}
	ll cost = 0;
	if (B <= C) {
		for (int i = 0; i < N; i++) {
			cost += A[i];
		}
		cost *= B;
	}
	else {
		ll BC = B + C;
		ll BCC = BC + C;
		for (int i = 0; i <= N - 3; i++) {
			if (A[i + 1] > A[i + 2]) {
				// 3개 짜리 구매를 위해 A[i + 1]과 A[i + 2]를 비슷하게 맞춰주는 작업
				ll two = A[i + 1] - A[i + 2];
				two = min(A[i], two);
				A[i] -= two;
				A[i + 1] -= two;
				cost += two * BC;
				// 3개짜리 최대로 구입
				ll three = min({ A[i], A[i + 1], A[i + 2] });
				A[i] -= three;
				A[i + 1] -= three;
				A[i + 2] -= three;
				cost += three * BCC;
				// A[i + 1] == 0이면 남은 A[i]처리
				if (A[i + 1] == 0) {
					cost += A[i] * B;
					A[i] = 0;
				}
			}
			else if (A[i + 1] <= A[i + 2]) {
				// 3개짜리 최대한 구입
				ll three = min({ A[i], A[i + 1], A[i + 2] });
				A[i] -= three;
				A[i + 1] -= three;
				A[i + 2] -= three;
				cost += three * BCC;
				// 2개짜리로 A[i] 최대한 소진
				ll two = min(A[i], A[i + 1]);
				A[i] -= two;
				A[i + 1] -= two;
				cost += two * BC;
				if (A[i] != 0) { // 1개 짜리로 A[i] 소진
					cost += A[i] * B;
					A[i] = 0;
				}
			}
		}
		// 맨 마지막 2개 공장에서 구입
		ll two = min(A[N - 2], A[N - 1]);
		A[N - 2] -= two;
		A[N - 1] -= two;
		cost += two * BC;
		cost += (A[N - 2] * B + A[N - 1] * B);
		A[N - 2] = 0;
		A[N - 1] = 0;
	}
	
	std::cout << cost << "\n";

	return 0;
}