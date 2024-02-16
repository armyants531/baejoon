#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int E, S, M;
	cin >> E >> S >> M;
	for (int i = 1; i <= 9280; i++) {
		int e, s, m;
		if (i % 15 == 0) {
			e = 15;
		}
		else {
			e = i % 15;
		}
		if (i % 28 == 0) {
			s = 28;
		}
		else {
			s = i % 28;
		}
		if (i % 19 == 0) {
			m = 19;
		}
		else {
			m = i % 19;
		}
		if (E == e && S == s && M == m) {
			cout << i << "\n";
			break;
		}
	}
	return 0;	
}