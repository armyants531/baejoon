#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		int cnt = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) cnt++;
		}
		cout << "Hamming distance is " << cnt << '.' << "\n";
	}

	return 0;
}