#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int sum = s.size();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':') {
			sum++;
		}
		else if (s[i] == '_') {
			sum += 5;
		}
	}
	cout << sum;

	return 0;
}