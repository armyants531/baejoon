#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> arr(N + 1);
	for (int m = 0; m < M; m++) {
		int i, j, k;
		cin >> i >> j >> k;
		for (int a = i; a <= j; a++) {
			arr[a] = k;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}
}