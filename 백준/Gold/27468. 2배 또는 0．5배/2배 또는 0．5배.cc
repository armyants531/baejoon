#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int re = N % 4;
	cout << "YES" << "\n";
	if (re == 0) {
		int num = 0;
		int arr[4] = { 1, 2, -1, 2 };
		for (int i = 0; i < N; i++) {
			num += arr[i % 4];
			cout << num << " ";
		}
	}
	if (re == 1) {
		int num = 0;
		int arr[4] = { 1, 2, -1, 2 };
		for (int i = 0; i < N; i++) {
			num += arr[i % 4];
			cout << num << " ";
		}
	}
	if (re == 2) {
		int num = 0;
		int arr[4] = {2, -1, 2, 1 };
		for (int i = 0; i < N; i++) {
			num += arr[i % 4];
			cout << num << " ";
		}
	}
	if (re == 3) {
		int num = 0;
		int arr[4] = { 1, 2, -1, 2 };
		for (int i = 0; i < N; i++) {
			num += arr[i % 4];
			cout << num << " ";
		}
	}
}