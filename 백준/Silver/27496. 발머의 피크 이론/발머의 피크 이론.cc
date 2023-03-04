#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, L;
	cin >> N >> L;
	vector<int> arr(N + L);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr[i] += a;
		arr[i + L] -= a;
	}
	int pre_sum = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		pre_sum += arr[i];
		if (pre_sum >= 129 && pre_sum <= 138) {
			cnt++;
		}
		//cout << pre_sum << " ";
	}
	cout << cnt << "\n";
}