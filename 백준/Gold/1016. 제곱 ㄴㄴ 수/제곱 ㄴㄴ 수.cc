// 제곱 ㄴㄴ 수  // number theory  // prime number  // Sieve of Eratosthenes
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll min_val, max_val;
vector<ll> arr(1000001); // min_val 부터 max_val 까지 담음 

void sieve(ll min_val, ll max_val) {
	for (ll i = 0; i <= max_val - min_val; i++) {
		arr[i] = i + min_val;
	}

	for (ll i = 2; i <= sqrt(max_val); i++) { // i는 max_val의 제곱근 이하 
		if (i >= min_val && arr[i - min_val] == 0) // 이미 처리된 경우 continue(ex: 4의 제곱은 2의 제곱의 배수이므로 처리 안함)
			continue; 
		ll square_i = i * i;
		ll j = min_val / square_i;
		if (min_val % square_i) { // 나누어 떨어지지 않으면
			j++;
		}
		while (square_i * j <= max_val) { // i * i * j 가 max_val 이하일 때 까지
			arr[square_i * j - min_val] = 0;
			j++;
		}
	}
	/*
	for (int i = 0; i <= max_val - min_val; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	*/
}

int main() {
	cin >> min_val >> max_val;
	sieve(min_val, max_val);
	int cnt = 0;
	for (int i = 0; i <= max_val - min_val; i++) {
		if (arr[i] != 0) {
			cnt++;
		}
	}
	cout << cnt << "\n";
}