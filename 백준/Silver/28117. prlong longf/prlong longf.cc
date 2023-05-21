#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll table[20][20];

ll combi(int n, int r) {
	if (table[n][r] != 0) {
		return table[n][r];
	}
	if (n == r || r == 0) {
		return 1;
	}
	else {
		return combi(n - 1, r - 1) + combi(n - 1, r);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	string s;
	cin >> s;
	string longlong = "longlong";
	vector<int> arr;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'l') {
			bool isSame = true;
			for (int j = 1; j < 8; j++) {
				if (s[i + j] != longlong[j]) {
					isSame = false;
					break;
				}
			}
			if (isSame) {
				cnt++;
				if (i + 3 < N) {
					i += 3;
				}
			}
		}
		else if (cnt != 0) {
			arr.push_back(cnt + 1);
			cnt = 0;
		}
	}
	ll sol = 1;
	for (int i = 0; i < arr.size(); i++) {
		ll cnt = 1;
		int n = arr[i] - 1;
		int r = 1;
		while (n >= r) {
			cnt += combi(n, r);
			n--;
			r++;
		}
		sol *= cnt;
	}
	cout << sol << "\n";
}