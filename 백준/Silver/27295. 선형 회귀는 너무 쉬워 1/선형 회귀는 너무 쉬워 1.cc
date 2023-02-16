#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, b;
	cin >> n >> b;
	ll sum_x = 0;
	ll sum_y = 0;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		sum_x += x;
		sum_y += y;
	}
	if (sum_x == 0) { // 여러 개
		cout << "EZPZ";
	}
	else {
		ll up = sum_y - n * b;
		ll down = sum_x;
		ll re = up % down;
		if (re == 0) { // 정수
			cout << up / down;
		}
		else { // 기약분수
			bool isPos;
			if ((double)up / down > 0) {
				isPos = true;
			}
			else {
				isPos = false;
			}
			up = abs(up);
			down = abs(down);
			if (up > down) {
				for (ll i = 2; i <= sqrt(down); i++) {
					if (up % i == 0 && down % i == 0) {
						up /= i;
						down /= i;
						i--;
					}
				}
			}
			else {
				for (ll i = 2; i <= sqrt(up); i++) {
					if (up % i == 0 && down % i == 0) {
						up /= i;
						down /= i;
						i--;
					}
				}
			}
			if (isPos) {
				cout << up << "/" << down;
			}
			else {
				cout << "-" << up << "/" << down;
			}
		}
	}
}