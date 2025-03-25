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
	double hlo, hhi, slo, shi, vlo, vhi, R, G, B, M, m, V, S, H;
	cin >> hlo >> hhi >> slo >> shi >> vlo >> vhi >> R >> G >> B;
	M = max({R, G, B});
	m = min({R, G, B});
	V = M;
	S = 255 * (V - m) / V;
	if (V == R) {
		H = 60 * (G - B) / (V - m);
	}
	else if (V == G) {
		H = 120 + 60 * (B - R) / (V - m);
	}
	else {
		H = 240 + 60 * (R - G) / (V - m);
	}
	if (H < 0) {
		H += 360;
	}
	//cout << H << " " << S << " " << V << "\n"; 
	if (H >= hlo && H <= hhi && S >= slo && S <= shi && V >= vlo && V <= vhi) {
		cout << "Lumi will like it." << "\n";
	}
	else {
		cout << "Lumi will not like it." << "\n";
	}
	
	return 0;
}