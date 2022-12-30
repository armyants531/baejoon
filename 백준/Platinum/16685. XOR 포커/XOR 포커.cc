// XOR 포커  // linear algebra  // gaussian elimination
// Xor Maximization인데 짝수 개를 골라야 함
// 1. ai가 정답에 포함: 나머지를 홀수 개 뽑음 -> 한 원소(처음 입력받는 수)를 선택해 xor 연산을 수행 -> 짝수 개 뽑으면 됨
// 2. ai가 정답에 불포함: 나머지를 짝수 개 뽑음 -> 처음 입력 받는 수(a1)을 짝수번 xor연산해주면 a1^...^a1 = 0
// 처음 입력받는 수와 다른 수들을 xor 취한 값의 xor basis를 구하고 이들의 Xor Maximization을 구하면 항상 짝수 개를 선택할 수 있음
// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=tmd3282&logNo=221514149066 참고
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> basis(60, 0); // 2^60 = 1,152,921,504,606,847,000이므로 2^59까지만 표현하면 됨

// 처음 입력받는 수와 다른 수들을 xor 취한 값의 XOR basis를 구하기
int calcBasis(int N) {
	int lead = 0; // leading entry idx
	ll first;
	cin >> first;
	for (int i = 1; i < N; i++) {
		ll a;
		cin >> a;
		a ^= first; // 처음 입력받는 수와 XOR
		for (int j = 59; j >= 0; j--) {
			if (((1LL << j) & a) == 0) {
				continue;
			}
			lead = max(lead, j); // leading entry idx 갱신
			if (basis[j] != 0) {
				a ^= basis[j]; // leading entry가 맞는 row가 있으면, XOR연산을 수행
			}
			else { // basis에 주어진 숫자를 끼워넣고 종료
				basis[j] = a;
				break;
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
	// leading entry의 인덱스부터 시작하여 짝수 개의 카드 고르기
	for (int i = lead; i >= 0; i--) {
		xorSum = max(xorSum, xorSum ^ basis[i]);
	}
	cout << xorSum << "\n";

	return 0;
}