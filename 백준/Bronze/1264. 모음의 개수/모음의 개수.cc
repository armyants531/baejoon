#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		char a[256];
		cin.getline(a, 256);
		if (a[0] == '#') {
			break;
		}
		int cnt = 0;
		for (int i = 0; i < strlen(a); i++) {
			if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U') {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
}