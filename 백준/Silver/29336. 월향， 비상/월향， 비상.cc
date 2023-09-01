// 월향, 비상
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
using pdd = pair<double, double>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end(), greater<int>());
	int idx = 0; // 기여할 운영진 인덱스  
	int tot = 0; // 퀄리티의 합 
	bool can = true;
	int T, Q;
	for (int i = 0; i < M; i++) {
		cin >> T >> Q;
		while (Q > tot && idx != N) {
			//cout << A[idx] + T << "\n";
			tot += A[idx] + T;
			idx++;
		} 
		if (Q > tot) { // 안 됨 
			can = false;	
		}
	}
	if (can) {
		for (int i = idx; i < N; i++) {
			tot += A[i] + T;
		}
		cout << tot << "\n";
	}
	else {
		cout << -1 << "\n";
	}
	
	return 0;
}