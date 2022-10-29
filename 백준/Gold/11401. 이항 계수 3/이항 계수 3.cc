// 이항계수 3
#include <iostream>
using namespace std;

static long long p = 1000000007;

long long factorial(long long n) {
	long long val = 1;
	while (n >= 2) {
		val = (val * n) % p;
		n--;
	}
	return val;
}

long long power(long long a, long long b) {
	if (b == 1)
		return a % p;

	long long pow = power(a, b / 2) % p;
	if (b % 2 == 0)
		return pow * pow % p;
	else
		return (pow * pow % p) * (a % p) % p;
}

long long binomial(long long n, long long k) {
	long long a = factorial(n - k) * factorial(k);
	return factorial(n) * power(a, p-2) % p; // (n! mod p) x (((n-k)!k!)^(-1) mod p) mod p = (n! mod p) x (((n-k)!k!)^(p-2) mod p)
}

int main() {
	long long n, k;

	cin >> n >> k;
	cout << binomial(n, k) << "\n";

	return 0;
}