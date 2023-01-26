// 소수의 연속합  // sieve of eratosthenes // two pointer
#include <bits/stdc++.h>

using namespace std;

vector<int> sieve(4000001);
vector<int> primes;

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

int count(int N) {
	int low = 0, high; // low, high pointer
	int sum = 0;
	int cnt = 0;
	for (high = 0; high < primes.size(); high++) { // high를 오른쪽으로 이동
		sum += primes[high];
		while (sum >= N && low <= high) { // sum이 N이상이고 low가 high이하이면
			if (sum == N) {
        cnt++;
      }
			sum -= primes[low]; // low를 오른쪽으로 이동
			low++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	findPrime(N);
  for (int i = 2; i <= N; i++) {
    if (sieve[i]) {
      primes.push_back(i);
    }
  }
	cout << count(N) << "\n";
}