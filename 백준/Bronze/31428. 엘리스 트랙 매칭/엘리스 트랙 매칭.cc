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
	int N;
	cin >> N;
	int c = 0, s = 0, i = 0, a = 0;
	for (int t = 0; t < N; t++) {
		char ch;
		cin >> ch;
		if (ch == 'C') c++; 
		else if (ch == 'S') s++; 
		else if (ch == 'I') i++;
		else a++;
	}
	char ch2;
	cin >> ch2;
	if (ch2 == 'C') cout << c << "\n";
	else if (ch2 == 'S') cout << s << "\n";
	else if (ch2 == 'I') cout << i << "\n";
	else cout << a << "\n";
	
	return 0;
}