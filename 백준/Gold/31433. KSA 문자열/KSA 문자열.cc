#include <bits/stdc++.h> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	string str1 = "KSA";
	string str2 = "SAK";
	string str3 = "AKS";
	int idx1 = 0;
	int idx2 = 0;
	int idx3 = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (str1[idx1] == s[i]) {
			idx1++;
			idx1 %= 3;
			cnt1++;
		}
		if (str2[idx2] == s[i]) {
			idx2++;
			idx2 %= 3;
			cnt2++;
		}
		if (str3[idx3] == s[i]) {
			idx3++;
			idx3 %= 3;
			cnt3++;
		}
	}
	if (cnt2 == n) {
		cnt2 -= 1;
	}
	if (cnt3 == n) {
		cnt3 -= 2;
	}
	else if (cnt3 == n - 1) {
		cnt3 -= 1;
	}
	int cnt = max({cnt1, cnt2, cnt3});
	cout << 2*(n - cnt) << "\n";
	return 0;
}