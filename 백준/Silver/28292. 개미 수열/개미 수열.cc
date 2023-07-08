#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	if (N <= 2) {
		cout << 1;
	}
	else if (N <= 5) {
		cout << 2;
	}
	else {
		cout << 3;
	}
	return 0;
}