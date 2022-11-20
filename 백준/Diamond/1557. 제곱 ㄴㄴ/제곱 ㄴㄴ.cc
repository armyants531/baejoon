// 제곱 ㄴㄴ  // math // binary search // inclusion-exclusion principle
// https://ohgym.tistory.com/19 참고
// 구간 내의 square-free의 개수 구하기
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> mu(45001, -1); // sqrt(2K)보다 크게 넉넉하게 잡음
vector<bool> isPrime(45001, true); // 소수인지 확인하는 리스트
vector<int> p_vec; // sqrt_K 이하의 소수 리스트

ll square_free_num(ll K) {
	// K 이하의 square-free integer의 갯수(F) 구하기
	ll F = 0;
	for (ll i = 1; i*i <= K; i++) {
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
	// mu 리스트를 구현
	mu[1] = 1;
	for (int i = 2; i <= 45000; i++) {
		if (isPrime[i]) {
			p_vec.push_back(i); // 소수 추가
		}
		for (int p = 0; p < p_vec.size(); p++) {
			int p_val = p_vec[p];
			int ip = i * p_val;
			if (ip > 45000) {
				break;
			}
			isPrime[ip] = false; // i * p_val는 소수가 아님
			if (i % p_val == 0) { // i가 p_val의 배수이면 i * p_val(ip)는 제곱수를 인자로 가짐
				mu[ip] = 0; // ip가 제곱수를 인자로 가지므로 0
				break;
			}
			mu[ip] = mu[i] * mu[p_val]; // ip의 mu값 계산
		}
	}
	
	// 이분 탐색을 통해 K번째 제곱ㄴㄴ수를 구하기
	ll low = K;
	ll high = 2*K;
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