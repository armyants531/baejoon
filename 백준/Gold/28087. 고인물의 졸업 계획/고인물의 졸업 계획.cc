// 고인물의 졸업 계획  // greedy
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N, M;
	cin >> N >> M;
	vector<ll> S(M);
	for (int i = 0; i < M; i++) {
		cin >> S[i];
	}
	bool one = false; // 한 개만으로 가능?
	vector<ll> C;  // 1 <= x < N 
	for (int i = 0; i < M; i++) {
		if (S[i] <= 2 * N) {
			if (S[i] >= N) {
				cout << 1 << "\n";
				cout << i + 1 << "\n";
				one = true;
				break;
			}
			else {
				C.push_back(i);
			}
		}
	}
	if (!one) {
		ll sum = 0;
		vector<ll> idx;
		for (int i = 0; i < C.size(); i++) {
			sum += S[C[i]];
			idx.push_back(C[i] + 1);
			if (sum >= N) {
				break;
			}
		}
		cout << idx.size() << "\n";
		for (int i = 0; i < idx.size(); i++) {
			cout << idx[i] << "\n";
		}
	}
	return 0;
}