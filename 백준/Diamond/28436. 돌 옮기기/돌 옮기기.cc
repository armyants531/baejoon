// 돌 옮기기  // 게임이론
// 돌은 왼쪽으로만 움직일 수 있으므로 최대한 맨 뒤 돌을 움직여 상대에게 추가 턴을 주지 않아야 한다.
// 마지막 색을 B라 하면, 가장 뒤의 W는 움직이지 않고 그 앞의 W를 움직여 추가 턴을 주지 않도록 한다.
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
		string s;
		cin >> s;
		int B = 0, W = 0; // 돌의 수 카운트(여분의 턴 수 세기 위한) 
		int B_cnt = 0, W_cnt = 0; // 여분의 턴 수 
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == 'W') {
				if (B > 0) { // 이 W를 fix 
					B = 0;
				} 
				else {
					W++;
				}
			}
			else if (s[i] == 'B') {
				if (W > 0) { // 이 B를 fix 
					W = 0;
				}
				else {
					B++;
				}
			}
			else { // s[i] == '.'
				if (B > 0) {
					B_cnt += B;
				}
				else if (W > 0) {
					W_cnt += W;
				}
			}
		}
		if (W_cnt > B_cnt) {
			cout << "WHITE" << "\n";
		}
		else {
			cout << "BLACK" << "\n";
		}
	}
}