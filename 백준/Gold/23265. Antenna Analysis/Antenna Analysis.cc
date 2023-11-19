#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define INF 2000000000

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n, c;
	cin >> n >> c;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int pre_min = x[0];
    int pre_max = x[0];
    int min_idx = 0;
    int max_idx = 0;
    y[0] = 0;
    int sumc = 0;
	for (int i = 1; i < n; i++) {
        int mx = 0;
        sumc += c;
        mx = max(mx, abs(pre_max - x[i]) - sumc + max_idx * c);
        mx = max(mx, abs(pre_min - x[i]) - sumc + min_idx * c);
        y[i] = mx;
        if (pre_max + max_idx * c < x[i] + sumc) {
            pre_max = x[i];
            max_idx = i;
        }
        if (-pre_min + min_idx * c < -x[i] + sumc) {
            pre_min = x[i];
            min_idx = i;
        }
        //cout << max_idx << " " << min_idx << "\n";
	}
    for (int i = 0; i < n; i++) {
        cout << y[i] << " ";
    }
  
	return 0;
}