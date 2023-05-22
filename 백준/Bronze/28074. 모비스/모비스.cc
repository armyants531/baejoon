#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	int m = 0;
	int o = 0;
	int b = 0;
	int i = 0;
	int s = 0;
	cin >> str;
	for (int idx = 0; idx < str.size(); idx++) {
		if (str[idx] == 'M') {
			m++;
		}
		else if (str[idx] == 'O') {
			o++;
		}
		else if (str[idx] == 'B') {
			b++;
		}
		else if (str[idx] == 'I') {
			i++;
		}
		else if (str[idx] == 'S') {
			s++;
		}
	}
	if (m > 0 && o > 0 && b > 0 && i > 0 && s > 0) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
}