#include <iostream>

using namespace std;

int main() {
	int arr[8] = { 0, };
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}
	bool isAscending = true;
	bool isDesending = true;
	for (int i = 1; i < 8; i++) {
		if (arr[i - 1] < arr[i]) {
			isDesending = false;
		}
		else {
			isAscending = false;
		}
	}
	if (isAscending)
		cout << "ascending" << "\n";
	else if (isDesending)
		cout << "descending" << "\n";
	else
		cout << "mixed" << "\n";

	return 0;
}