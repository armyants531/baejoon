// 이항 계수 5  // 수학  // 정수론  // 소수 판정  // 에라토스테네스의 체
// nCk = n! / (k! * (n - k)!)
// (A * B) % M = ((A % M) * (B % M)) % M (mod M)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> sieve(4000001);
vector<int> primes; // 소수 저장 배열
vector<int> numOfPrime(4000001);

// N 이하의 소수 찾기(sieve of eratosthenes)
void findPrime(int N) {
	for (int i = 2; i <= N; i++) {
		sieve[i] = i;
	}
	int sqr = sqrt(N);
	for (int i = 2; i <= sqr; i++) {
		if (sieve[i] == 0) continue;
		for (int j = i * i; j <= N; j += i) {
			sieve[j] = 0;
		}
	}
}

// nCk를 소인수분해 했을 때, 각 소인수의 개수를 세는 함수
void cntPrime(int N, int K) {
	for (auto p : primes) {
		ll factor = p;
		while (factor <= N) {
			numOfPrime[p] += N / factor;
			numOfPrime[p] -= (N - K) / factor;
			numOfPrime[p] -= K / factor;
			factor *= p;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K, M;
	cin >> N >> K >> M;
	findPrime(N);
	for (int i = 2; i <= N; i++) {
		if (sieve[i]) {
			primes.push_back(i);
		}
	}
	cntPrime(N, K);
	// 소인수들을 곱하고 모듈로 연산하는 것을 반복
	ll ans = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < numOfPrime[i]; j++) {
			ans *= i;
			ans %= M;
		}
	}
	cout << ans << "\n";
}