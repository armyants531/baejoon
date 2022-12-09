// 피보나치 수 3  // 분할 정복을 이용한 거듭제곱
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> arr(1500001);
ll T;

int pisano_T(int M) {
	int a = 0;
	int b = 1;
	int T = 0;
	while (true) {
		int temp = (a + b) % M;
		a = b;
		b = temp;
		T++;
		if (a == 0 && b == 1) {
			break;
		}
	}
	return T;
}

ll fibonacci(ll n) {
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
	}
	return arr[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	T = pisano_T(1000000); //  1,500,000

	ll remainder = n % T;
	cout << fibonacci(remainder) << "\n";

	return 0;
}
