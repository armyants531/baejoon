// 2021은 무엇이 특별할까?  // number theory  // Sieve of Eratosthenes
#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(401, 0);
	for (int i = 2; i <= 400; i++) {
		arr[i] = i;
	}

	int sqr = sqrt(400);
	for (int i = 2; i <= 400; i++) {
		if (arr[i] == 0) {
			continue;
		}
		// i * 2 ~ i * (i - 1)은 이미 처리됨 
		for (int j = i * i; j <= 400; j += i) {
			arr[j] = 0;
		}
	}
	vector<int> primes;
	for (int i = 2; i <= 400; i++) {
		if (arr[i] != 0) {
			primes.push_back(arr[i]);
		}
	}
	for (int i = 0; i < primes.size() - 1; i++) {
		if (primes[i] * primes[i + 1] > N) {
			cout << primes[i] * primes[i + 1] << "\n";
			break;
		}
	}

	return 0;
}