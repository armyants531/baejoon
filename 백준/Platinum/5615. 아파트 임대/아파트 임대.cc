// 아파트 임대  // 밀러-라빈 소수 판별법
// https://restudycafe.tistory.com/450 참고  
// A = 2xy + x + y, 2A + 1 = 4xy + 2x + 2y + 1 = (2x + 1)(2y + 1)
// 2A + 1이 소수이면 이를 만족하는 양의 정수 x, y는 존재하지 않음
  
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
using ull = unsigned long long; 

ull B[] = {2, 7, 61};

// a^b mod p
ull power(ull a, ull b, ull p) {
	ull ans = 1;
	while (b) {
		if (b % 2 == 1) {
			ans *= a;
			ans %= p;
		}
		b /= 2;
		a = a * a % p;
	}
	return ans;
}

// 소수인지 판별 
bool isPrime(ull p, int idx) {
	ull d = p - 1; // 지수
	ull a = B[idx]; // 밑 
	if (a == p) { // a는 소수이므로 p도 소수 
		return true;
	}
	while (d % 2 == 0) {
		d /= 2; 
		if (power(a, d, p) == p - 1) return true; // a^d + 1은 p의 배수 
	}
	ull tmp = power(a, d, p);
	if (tmp == 1) return true; // a^d - 1은 p의 배수 
	else if (tmp == p - 1) return true; // a^d + 1은 p의 배수 
	else return false;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		ull A;
		cin >> A;
		int p = 2 * A + 1;
		bool isP = true;
		for (int j = 0; j < 3; j++) {
			if (!isPrime(p, j)) {
				//cout << i << " " << j << "\n";
				isP = false;
				break;
			}
		}
		if (isP) cnt++;
	}
	cout << cnt << "\n";
	
	return 0;
}