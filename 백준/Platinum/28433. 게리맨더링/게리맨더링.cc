// 게리맨더링
// A[i] > 0: A[i]를 이전 구간에 포함시켰을 때 음수에서 양수가 되면 포함시키고, 아니면 새로운 구간 시작
// A[i] < 0: A[i]를 이전 구간에 포함시켰을 때 양수에서 0 이하가 되면 포함시키지 말고 아니면 포함 
// 0은 무시 
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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int plus = 0; // 양의 구간 개수 
		int minus = 0; // 음의 구간 개수 
		int pre = 0; // 누적합 
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			if (a < 0) {
				if (pre > 0 && pre + a <= 0) { // 양수 -> 0이하 
					plus++; // 불포함(양수 개수를 줄이면 손해)
					pre = a; 
				}
				else { // 포함 
					pre += a;
				}
			}
			else if (a > 0) {
				if (pre < 0 && pre + a > 0) { // 음수 -> 양수 
					pre += a; // 포함(음수 개수를 줄이면 이득)
				}
				else { // 불포함
					if (pre > 0) {
						plus++;
					}	
					else if (pre < 0) {
						minus++;
					}
					pre = a;
				} 
			}
		}
		if (pre > 0) plus++;
		else if (pre < 0) minus++;
		if (plus > minus) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	
	return 0;
}