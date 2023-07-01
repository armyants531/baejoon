#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> a(N);
	vector<int> pre1(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	// ai를 N극, aj를 S극이라 하자
	// i > j -> ai - aj - k(i - j) = (ai - ki) - (aj - kj)
	int min_j = 2000000000;
	int max_c1 = -2000000000;
	for (int i = 1; i < N; i++) {
		min_j = min(a[i - 1] - K * (i - 1), min_j); // 핵심!
		max_c1 = max(a[i] - K * i - min_j, max_c1);
	}
	// j > i -> ai - aj - k(j - i) = (ai + ki) - (aj + kj)
	min_j = 2000000000;
	int max_c2 = -2000000000;
	for (int i = N - 2; i >= 0; i--) {
		min_j = min(a[i + 1] + K * (i + 1), min_j);
		max_c2 = max(a[i] + K * i - min_j, max_c2);
	}
	cout << max(max_c1, max_c2) << "\n";
	return 0;
}