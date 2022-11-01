#include <iostream>

using namespace std;

long long power(long long a, long long b, long long c) {
	if (b == 1)
		return a % c;

	long long pow = power(a, b / 2, c) % c;
	if (b % 2 == 0)
		return pow * pow % c;
	else
		return (pow * pow % c) * (a % c) % c;
}

int main() {
	long long a, b, c;
	cin >> a >> b >> c;

	cout << power(a, b, c) << "\n";
	
	return 0;
}