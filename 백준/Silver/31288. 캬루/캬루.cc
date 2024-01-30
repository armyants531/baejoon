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
	for (int t = 0; t < T; t++) {
		int N;
		string P;
		cin >> N >> P;
		int sum = 0; // mod 3
		for (int i = 0; i < N; i++) {
			sum += (P[i] - '0');			
		}
		int cnt = 0;
		for (int i = N - 1; i >= 0; i--) {
			bool flag = false;
			int num = P[i] - '0';
			int j = 0;
			if (i == 0) {
				j = 4; // 3은 소수 
			}
			for (; j <= 9; j++) {
				if (num == j) {
					continue;
				}
				if (cnt == N) {
					flag = true;
					break;
				}
				if ((j + sum - num) % 3 == 0) {
					cnt++;
					string s = P;
					s[i] = (char)(j + '0');
					cout << s << " " << 3 << "\n";
				} 
			}
			if (flag) break;
		}
	}
	
	return 0;
}