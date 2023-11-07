#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int x, y, z, w, n;
	cin >> x >> y >> z >> w >> n;
	cout << max(n * 4 - x - y - z - w, (int)0); 
	
	return 0;
}