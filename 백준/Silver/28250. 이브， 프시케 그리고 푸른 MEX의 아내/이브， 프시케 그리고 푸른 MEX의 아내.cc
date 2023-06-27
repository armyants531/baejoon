// 이브, 프시케 그리고 푸른 MEX의 아내  // 조합론
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	ll z = 0;
	ll o = 0;
	ll e = 0;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) {
			z++;
		}
		else if (a == 1) {
			o++;
		}
		else {
			e++;
		}
	}
	// {0, 1} -> 2, {0, X} -> 1(X != 1)
	cout << z * o * 2 + z * e + z * (z - 1) / 2 << "\n";
	return 0;
}