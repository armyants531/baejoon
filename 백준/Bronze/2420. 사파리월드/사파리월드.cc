#include <iostream>

using namespace std;

int main() {
	long n, m;
	cin >> n >> m;
	if (n > m) {
		cout << n - m << "\n";
	}
	else {
		cout << m - n << "\n";
	}
	return 0;
}