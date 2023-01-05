#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	if (N >= 200 && N < 206) {
		cout << 1 << "\n";
	}
	else if (N >= 206 && N < 218) {
		cout << 2 << "\n";
	}
	else if (N >= 218 && N < 229) {
		cout << 3 << "\n";
	}
	else {
		cout << 4 << "\n";
	}

	return 0;
}