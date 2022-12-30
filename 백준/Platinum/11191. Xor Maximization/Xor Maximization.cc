// Xor Maximization  // linear algebra  // gaussian elimination
// https://koosaga.com/132 참고
// RREF(Reduced Row Echelon Form): 주어진 숫자를 하나씩 넣는데 넣을 숫자의 가장 큰 bit를 보고
// 현재 행렬에서 leading entry가 맞는 row가 있으면, XOR연산을 수행하고 더 작은 비트로 넘어가 이를 반복한다. 
// 없으면, 주어진 숫자를 끼워넣고 종료한다.
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> basis(60, 0); // 2^60 = 1,152,921,504,606,847,000이므로 2^59까지만 표현하면 됨

// XOR basis를 구하기
int calcBasis(int N) {
	int lead = 0; // leading entry idx
	for (int i = 0; i < N; i++) {
		ll a;
		cin >> a;
		for (int j = 59; j >= 0; j--) {
			if ((1LL << j) & a) { // leading entry 찾기
				lead = max(lead, j); // leading entry idx 갱신
				if (basis[j] != 0) { // leading entry가 맞는 row가 있으면, XOR연산을 수행
					a ^= basis[j];
				}
				else { // basis에 주어진 숫자를 끼워넣고 종료
					basis[j] = a;
					break;
				}
			}
		}
	}
	return lead;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	// leading entry idx
	int lead = calcBasis(N);
	
	// basis를 구한 후, 최댓값 구하기 
	ll xorSum = 0;
	for (int i = lead; i >= 0; i--) {
		xorSum = max(xorSum, xorSum ^ basis[i]);
	}
	cout << xorSum << "\n";

	return 0;
}