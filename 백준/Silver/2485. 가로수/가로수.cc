#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (b > 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> diff(N - 1);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++) {
		diff[i - 1] = arr[i] - arr[i - 1];
	}
	int g = gcd(diff[0], diff[1]);
	for (int i = 2; i < N - 1; i++) {
		g = gcd(g, diff[i]);
	}
	int cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		cnt += diff[i] / g - 1;
	}
	cout << cnt << "\n";
}