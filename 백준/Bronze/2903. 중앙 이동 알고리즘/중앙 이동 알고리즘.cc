#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int sum = 0;
	int a = 2;
	for (int i = 1; i <= N; i++) {
		a = 2 * a - 1;
	}
	cout << a * a << "\n";
	
	return 0;
}