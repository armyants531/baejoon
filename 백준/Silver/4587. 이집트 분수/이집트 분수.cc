// 이집트 분수  // math  // number theory  // Euclidean algorithm
// 최소 공배수 = 두 수의 곱 / 최대 공약수
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	ll c;
	while (b > 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll M, N;
	cin >> M >> N;
	while (M != 0) {
		deque<ll> dq;
		ll i = 2;
		while (M != 0) {
			if ((double)M / N >= double(1) / i) {
				ll lcm;
				if (N > i) {
					lcm = N * i / gcd(N, i);
				}
				else {
					lcm = i * N / gcd(i, N);
				}
				ll next_M = M * lcm / N - lcm / i;
				ll next_N = lcm;
				if (next_M != 0) {
					ll next_gcd = gcd(next_M, next_N);
					next_M /= next_gcd;
					next_N /= next_gcd;
				}
				if (next_N < 1000000) {
					M = next_M;
					N = next_N;
					dq.push_back(i);
				}
				else { // 다음으로 큰 단위 분수로 넘어감
					i++;
					continue;
				}
			}
			else {
				i++;
			}
		}
		while (!dq.empty()) {
			cout << dq.front() << " ";
			dq.pop_front();
		}
		cout << "\n";
		cin >> M >> N;
	}
	
	return 0;
}