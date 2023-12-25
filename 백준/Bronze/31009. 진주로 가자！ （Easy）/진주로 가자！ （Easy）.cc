#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

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
	string D;
	int C;
	int cost;
	vector<int> c(N);
	for (int i = 0; i < N; i++) {
		cin >> D >> C;
		c[i] = C;
		if (D == "jinju") {
			cost = C;
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (cost < c[i]) {
			cnt++;
		}
	}
	cout << cost << "\n";
	cout << cnt << "\n";
	
	return 0;
}