// aFan Event Planning  // set  // binary search
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

set<int> set_d; // 이벤트 토큰 초기화 날짜(음수로 변환) 오름차순 저장
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	ll E;
	ll pre = 0;
	vector<ll> arr(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> E;
		pre += E;
		arr[i] = pre;
	}
	for (int i = 0; i < Q; i++) {
		int num, d, s, e;
		cin >> num;
		if (num == 1) {
			cin >> d;
			set_d.insert(-d);
		}
		else {
			cin >> s >> e;
			int max_ini = -1;
			if (set_d.size()) {
				// set에서 이분탐색
				auto it = set_d.upper_bound(-e);
				if (it != set_d.end()) {
					max_ini = *it;
					max_ini *= -1;
				}
			}
			if (max_ini == -1) {
				cout << arr[e] - arr[s - 1] << "\n";
			}
			else {
				cout << arr[e] - arr[max(max_ini, s - 1)] << "\n";
			}
		}
	}
}