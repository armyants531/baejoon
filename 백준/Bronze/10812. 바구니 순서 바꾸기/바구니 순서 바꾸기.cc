#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> arr(N + 1);
	vector<int> temp(N + 1);
	for (int i = 1; i <= N; i++) {
		arr[i] = i;
		temp[i] = i;
	}
	int i, j, k;
	for (int m = 0; m < M; m++) {
		cin >> i >> j >> k;
		int diff = k - i;
		for (int a = k; a <= j; a++) {
			arr[a - diff] = temp[a];
		}
		for (int a = i; a < k; a++) {
			arr[j - k + a + 1] = temp[a];
		}
		for (int a = i; a <= j; a++) {
			temp[a] = arr[a];
		}
		/*
		for (int i = 1; i <= N; i++) {
			cout << temp[i] << " ";
		}
		cout << "\n";
		*/
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}