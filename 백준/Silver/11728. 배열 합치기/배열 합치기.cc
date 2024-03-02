#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> a(N);
	vector<int> b(M);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> b[i];
	}
	int i1 = 0;
	int i2 = 0;
	while (i1 != N && i2 != M) {
		if (a[i1] < b[i2]) {
			cout << a[i1] << " ";
			i1++;
		}
		else {
			cout << b[i2] << " ";
			i2++;
		}
	}
	if (i1 != N) {
		for (int i = i1; i < N; i++) {
			cout << a[i] << " ";
		}
	}
	if (i2 != M) {
		for (int i = i2; i < M; i++) {
			cout << b[i] << " ";
		}
	}
	return 0;
}