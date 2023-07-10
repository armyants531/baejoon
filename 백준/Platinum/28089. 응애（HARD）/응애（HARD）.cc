// 응애(HARD)  // 수학  // 조합론  // 비트마스크
// bitset을 이용한 풀이
#include <bits/stdc++.h>
#define MAX 2000000

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N, M, K;
	cin >> N >> M >> K;
	vector<bitset<MAX>> W(3);
	auto& A = W[0];
	auto& B = W[1];
	auto& C = W[2];
	int num;
	for (ll i = 0; i < M; i++) {
		cin >> num;
		A[num] = 1;
	}
	for (ll v = 1; v <= K; v <<= 1) {
		ll shift = v % N;
		if ((K & v) == 0) continue;
		B = (A >> shift) | (A << N - shift); // 오른쪽 shift
		C = (A << shift) | (A >> N - shift); // 왼쪽 shift
		A = B ^ C;
		A <<= (MAX - N); // 오른쪽에 불필요한 비트 제거
		A >>= (MAX - N);
	}
	cout << A.count() << "\n";
	return 0;                                     
}