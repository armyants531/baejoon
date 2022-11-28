#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string S;
	cin >> S;
	ll alp[27] = { 0, };
	ll alp2[27] = { 0, };
	int idx1, idx2, idx3;
	idx1 = (int)(S[0] - 'A');
	idx2 = (int)(S[1] - 'A');
	idx3 = (int)(S[2] - 'A');
	alp[idx1] += 1;
	alp[idx2] += 1;
	alp[idx3] += 1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int A = (int)(str[0] - 'A');
		if (alp[A] != 0) {
			alp2[A]++;
		}
	}

	if (alp[idx1] <= alp2[idx1] && alp[idx2] <= alp2[idx2] && alp[idx3] <= alp2[idx3]) {
		
		if (idx1 != idx2 && idx1 != idx3 && idx2 != idx3) {
			ll b1 = alp2[idx1];
			ll b2 = alp2[idx2];
			ll b3 = alp2[idx3];
			cout << b1 * b2 * b3 << "\n";
		}
		else if (idx1 == idx2 && idx2 == idx3) {
			ll b1 = alp2[idx1] * (alp2[idx1] - 1) * (alp2[idx1] - 2) / 6;
			cout << b1 << "\n";
		}
		else if (idx1 == idx2) {
			ll b1 = alp2[idx1] * (alp2[idx1] - 1) / 2;
			ll b3 = alp2[idx3];
			cout << b1 * b3 << "\n";
		}
		else if (idx1 == idx3) {
			ll b1 = alp2[idx1] * (alp2[idx1] - 1) / 2;
			ll b2 = alp2[idx2];
			cout << b1 * b2 << "\n";
		}
		else if (idx2 == idx3) {
			ll b1 = alp2[idx1];
			ll b2 = alp2[idx2] * (alp2[idx2] - 1) / 2;
			cout << b1 * b2 << "\n";
		}
	}
	else {
		cout << 0 << "\n";
	}
}