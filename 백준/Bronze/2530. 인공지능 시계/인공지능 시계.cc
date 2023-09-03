#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	int sec = D + C;
	int minute = B + sec / 60;
	sec %= 60;
	int hour = A + minute / 60;
	minute %= 60;
	hour %= 24;
	cout << hour << " " << minute << " " << sec << "\n";	
	return 0;
}