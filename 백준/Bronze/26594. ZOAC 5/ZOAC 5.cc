#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	char a = str[0];
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (a == str[i]) {
			cnt++;
		}
		else {
			break;
		}
	}
	cout << cnt << "\n";


	return 0;
}