#include <iostream>

using namespace std;

int main() {
	double A, B;
	cin >> A >> B;
	cout << fixed;
	cout.precision(16);
	double ans = A / B;
	cout << ans << "\n";

	return 0;
}