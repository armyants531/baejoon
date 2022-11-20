// 제곱 ㄴㄴ  // math // binary search // inclusion-exclusion principle
// https://ohgym.tistory.com/19 참고
// 구간 내의 square-free의 개수 구하기
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> mu(45001, 0); // sqrt(2K)보다 크게 넉넉하게 잡음

ll square_free_num(ll K) {
	// K 이하의 square-free integer의 갯수(F) 구하기
	ll F = 0;
	for (ll i = 1; i * i <= K; i++) {
		F += mu[i] * (K / (i * i));
	}
	return F;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll K;
	cin >> K;
	// mu 리스트를 구현  // 배수의 홀짝성이 바뀌는 것을 이용한 코드
	mu[1] = 1;
	for (int i = 1; i <= 45000; i++) {
		for (int j = 2 * i; j <= 45000; j += i) {
			mu[j] -= mu[i];
		}
	}
	// 이분 탐색을 통해 K번째 제곱ㄴㄴ수를 구하기
	ll low = K;
	ll high = 2 * K;
	ll mid;
	ll ans = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (square_free_num(mid) >= K) {
			ans = mid; // K 이상일 때 답 갱신(K와 같은 경우 이후에 반복문 빠져나옴)
			high = mid - 1;
		}
		else { // square_free_num(mid, sqrt_mid) < K
			low = mid + 1;
		}
	}
	cout << ans << "\n"; // 정답 출력

	return 0;
}