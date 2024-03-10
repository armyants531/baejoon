#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

vector<string> a;
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll x, y, w, s;
	cin >> x >> y >> w >> s;
	if (2 * w <= s) {
		cout << (x + y) * w << "\n";
	}
	else if (w >= s) {
		ll ab = min(x, y);
		ll rem = x + y - 2 * ab;
		ll q = rem / 2;
		ll r = rem % 2;
		cout << w * r + s * (ab + 2 * q) << "\n";
	}
	else {
		ll ab = min(x, y);
		cout << w * (x + y - 2 * ab) + s * ab << "\n";
	}
	
	return 0;
}