#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	ll N;
	cin >> N;
	ll A, PA, B, PB;
	cin >> A >> PA >> B >> PB;
	ll max_v = -1;
	ll x = N / PA;
	ll y;
	ll a;
	ll b;
	while (x >= 0) {
		y = (N - x * PA) / PB;
		if (max_v < A * x + B * y) {
			max_v = A * x + B * y;
			a = x;
			b = y;
		}
		x--;
	}
	std::cout << a << " " << b << "\n";
	return 0;
}