#include <iostream>

#include <vector>

using namespace std;

int main() {

	int n = 10;	vector<int> arr(42, 0);

	for (int i = 0; i  <  n; i++) {

		int a;

		cin >> a;

		arr[a % 42] = 1;

	}

	int sum = 0;

	for (int i = 0; i < 42; i++) {

		sum += arr[i];

	}

	cout << sum;

	return 0;

}