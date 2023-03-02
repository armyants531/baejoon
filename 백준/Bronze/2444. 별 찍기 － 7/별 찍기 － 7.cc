#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = N - 1; j >= i; j--) {
			cout << " ";	
		}
		for (int j = 1; j <= 2 * i - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= 2 * N - 1 - 2 * i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	
	return 0;
}