#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> arr(N + 1);
	int a;
	for (int i = 1; i <= M; i++) {
		cin >> a;
		arr[a] = 1;
	}
	int ink = 0;
	int len = 0;
	int pre = 0;
	if (N == 1) {
		if (M == 0) {
			cout << 7 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (arr[i] == 1 && pre < 2 && len > 0) {
				len++;
				pre++;
			}
			else if (arr[i] == 1 && pre == 2) {
				pre = 0;
				ink += (len - 2) * 2 + 5;
				len = 0;
			}
			else if (arr[i] == 0) {
				pre = 0;
				len++;
			}
			//cout << ink << " ";
		}
		if (N >= 3) {
			if (arr[N - 2] == 0 && arr[N - 1] == 1 && arr[N] == 1) {
				ink += (len - 2) * 2 + 5;
			}
			else if (arr[N - 1] == 0 && arr[N] == 1) {
				ink += (len - 1) * 2 + 5;
			}
			else if (arr[N] == 0) {
				ink += len * 2 + 5;
			}
		}
		cout << ink << "\n";
	}
}