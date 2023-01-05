#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	int pre = -1;
	ll cnt = 0;
	ll potent = 0;
	for (int i = 0; i < str.length(); i++) {
		int a = str[i] - 'A';
		if (a == 0) {
			potent++;
		}
		if (pre == a) {
			if (a == 25) {
				cnt += potent;
			}
		}
		else if (pre + 1 == a) {
			pre++;
			if (a == 25) {
				cnt += potent;
			}
		}
		else {
			if (a == 0) {
				potent = 1;
				pre = 0;
			}
			else {
				potent = 0;
				pre = -1;
			}
		}
	}
	cout << cnt;
	return 0;
}