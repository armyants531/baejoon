#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, b = 0, s = 0, a = 0;
	cin >> N;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'B') {
			b++;
		}
		else if (str[i] == 'S') {
			s++;	
		}
		else {
			a++;		
		}
	}
	if (b == s && s == a) {
		cout << "SCU" << "\n";
	}
	else if (b == s && b > a) {
		cout << "BS" << "\n";		
	}
	else if (s == a && s > b) {
		cout << "SA" << "\n";
	}
	else if (b == a && b > s) {
		cout << "BA" << "\n";
	}
	else if (b > a && b > s) {
		cout << 'B' << "\n";
	}
	else if (s > b && s > a) {
		cout << 'S' << "\n";
	}
	else {
		cout << 'A' << "\n";
	}
	
	return 0;
}