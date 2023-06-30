#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	getline(cin, s);
	string ucpc = "UCPC";
	int idx = 0;
	bool can = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ucpc[idx]) {
			idx++;
			if (idx == 4) {
				can = true;
				break;
			}
		}
	}
	if (can) {
		cout << "I love UCPC" << "\n";
	}
	else {
		cout << "I hate UCPC" << "\n";
	}
	
	return 0;
}