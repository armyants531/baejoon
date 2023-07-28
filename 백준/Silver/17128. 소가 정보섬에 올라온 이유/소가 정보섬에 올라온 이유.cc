#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> cal(N);
	for (int i = 0; i < N; i++) {
		cal[i] = A[i] * A[(i + 1) % N] * A[(i + 2) % N] * A[(i + 3) % N];
	}
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += cal[i];
	}
	for (int i = 0; i < Q; i++) {
		int q;
		cin >> q;
		q--;
		cal[(q - 3 + N) % N] *= -1;
		cal[(q - 2 + N) % N] *= -1;
		cal[(q - 1 + N) % N] *= -1;
		cal[q] *= -1;
		sum += 2*(cal[(q - 3 + N) % N] + cal[(q - 2 + N) % N] + cal[(q - 1 + N) % N] + cal[q]);
		cout << sum << "\n";
	}
	return 0;
}