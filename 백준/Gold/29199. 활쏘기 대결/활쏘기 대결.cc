// 활쏘기 대결  // dp  // game theory 
// 결과적으로 표적을 두 사람이 나누어 갖는다 
// A[i]를 1 ~ i번 표적의 점수 합, B[i]을 1 ~ i번 째까지 정답이라하면
// B[1] = max(0, A[1]), B[i] = max(B[i-1], A[i]-B[i-1]); // max(i번 안 맞출 때 점수, i번 맞췄을 때 점수: A[i] - 상대방 점수)
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> A(n + 1), B(n + 1);
	int pre = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		pre += a;
		A[i] = pre;
	}
	B[1] = max((int)0, A[1]);
	for (int i = 2; i <= n; i++) {
		B[i] = max(B[i-1], A[i]-B[i-1]);	
	}
	cout << B[n] << "\n";
	
	return 0;
}