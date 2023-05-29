#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int a;
	cin >> a;
	int pre = a;
	int cnt = 0;
	int first = a;
	for (int i = 1; i < N; i++) {
		cin >> a;
		if (pre >= a) {
			cnt++;
		}
		pre = a;
	}
	if (pre >= first) {
		cnt++;
	}
	cout << cnt << "\n";

	return 0;
}