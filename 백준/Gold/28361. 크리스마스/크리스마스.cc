#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef long long ll;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int e = N / 3;
	int s = 1;
	cout << N << "\n";
	if (N % 3 == 0) {
		cout << 1 << " ";
		for (int i = 1; i <= e - 1; i++) {
			cout << s + 2 << " " << s + 1 << " " << s + 3 << " ";
			s += 3;
		}
		cout << s + 2 << " " << s + 1 << " " << 1;
	}
	else if (N % 3 == 1) {
		cout << 1 << " ";
		for (int i = 1; i <= e; i++) {
			cout << s + 2 << " " << s + 1 << " " << s + 3 << " ";
			s += 3;
		}
		cout << 1;
	}
	else if (N % 3 == 2) {
		cout << 1 << " ";
		cout << s + 1 << " " << s + 3 << " " << s + 2 << " " << s + 4 << " ";
		s += 4;
		N -= 4;
		for (int i = 1; i <= N / 3; i++) {
			cout << s + 2 << " " << s + 1 << " " << s + 3 << " ";
			s += 3;
		}
		cout << 1;
	}

	return 0;
}