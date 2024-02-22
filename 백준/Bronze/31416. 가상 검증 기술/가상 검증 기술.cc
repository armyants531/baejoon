#include <bits/stdc++.h> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int ta, tb, va, vb;
		cin >> ta >> tb >> va >> vb;
		int a, b;
		a = ta * va;
		b = tb * vb; 
		if (b >= a) {
			cout << b << "\n";
		}			
		else {
			int min_t = a;
			while (a > b) {
				a -= ta;
				b += ta;
				min_t = min(min_t, max(a, b));
			}
			cout << min_t << "\n";
		}
	}
	return 0;
}