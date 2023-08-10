// 기벡을 안배운다고?  // gcd
// 기약벡터 (a, b)와 수직이면 (b, -a), (-b, a) 
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int gcd(int x, int y) {
    if(x < y){
        swap(x, y);
    }
    int r;
    while(y){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<pii> v(N);
	map<pii, int> mp;
	int xy_zero = 0, x_zero = 0, y_zero = 0;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) {
			xy_zero++;
		} 
		else if (x == 0) {
			x_zero++;
		}
		else if (y == 0) {
			y_zero++;
		}
		else {
			int GCD = gcd(abs(x), abs(y));
			mp[{x / GCD, y / GCD}]++;
		}
	}
	int ans = xy_zero * (xy_zero - 1) + xy_zero * (N - xy_zero) * 2 + x_zero * y_zero * 2;
	for (auto p : mp) {
		ans += p.se * (mp[{p.fi.se, -p.fi.fi}]+mp[{-p.fi.se, p.fi.fi}]); 
	}
	// i < j이므로 2로 나눔 
	cout << ans / 2 << "\n";
	
	return 0;
}