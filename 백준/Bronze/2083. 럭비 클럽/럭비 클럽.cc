#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
using pdd = pair<double, double>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int age, w;
	cin >> s >> age >> w;
	while (s != "#" || age != 0 || w != 0) {
		string cata = "";
		if (age > 17 || w >= 80) {
			cata = "Senior";
		}
		else {
			cata = "Junior";
		}
		cout << s << " " << cata << "\n";
		cin >> s >> age >> w;
	}
	return 0;
}