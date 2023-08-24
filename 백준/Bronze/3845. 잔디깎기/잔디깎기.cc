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
	int nx, ny;
	double w;
	cin >> nx >> ny >> w;
	while (nx != 0 || ny != 0 || w != 0) {
		vector<double> vec1, vec2;
		double d = w / 2;
		for (int i = 0; i < nx; i++) {
			double x;
			cin >> x;
			vec1.push_back(x);
		}
		for (int i = 0; i < ny; i++) {
			double y;
			cin >> y;
			vec2.push_back(y);
		}
		sort(vec1.begin(), vec1.end());
		sort(vec2.begin(), vec2.end());
		double pre = -d;
		bool can = true;
		for (int i = 0; i < nx; i++) {
			if (vec1[i] > pre + w) {
				can = false;			
				break;
			}
			pre = vec1[i];
		}
		if (vec1[nx - 1] + d < 75) can = false;
		if (can) {
			pre = -d;
			for (int i = 0; i < ny; i++) {
				if (vec2[i] > pre + w) {
					can = false;
					break;
				}
				pre = vec2[i];
			}
			if (vec2[ny - 1] + d < 100) can = false;
		}
		if (can) {
			cout << "YES" << "\n";	
		}
		else {
			cout << "NO" << "\n";	
		}
		cin >> nx >> ny >> w;
	}

	return 0;
}