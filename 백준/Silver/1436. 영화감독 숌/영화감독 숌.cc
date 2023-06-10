#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int cnt = 0;
	int num = 666;
	while (cnt < n) {
		string s = to_string(num);
		bool have = false;
		for (int i = 0; i < s.size() - 2; i++) {
			if (s.substr(i, 3) == "666") {
				have = true;
				break;
			}
		}
		if (have) {
			cnt++;
			if (cnt == n) {
				cout << num << "\n";
				break;
			}
		}
		num++;
	}
	
	return 0;
}