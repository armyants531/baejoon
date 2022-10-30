#include <iostream>

using namespace std;

int main() {
	long long N;
	cin >> N;

	int remainder = N % 5; // (mod 5)
	
	if (remainder == 1 || remainder == 3 || remainder == 4)
		cout << "SK" << "\n";
	else
		cout << "CY" << "\n";
}