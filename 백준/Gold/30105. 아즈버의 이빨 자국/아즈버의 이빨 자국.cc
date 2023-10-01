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
	int N;
	cin >> N;
	vector<int> a(N);
	map<int, bool> mp;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		mp[a[i]] = true; // map에 표시 
	}
	int cnt = 0;
	vector<int> k_arr;
	int k;
	for (int i = 1; i < N; i++) {
		k = a[i] - a[0];
		bool posi = true;
		for (int j = 0; j < N; j++) { // 모든 좌표 좌, 우로 k 만큼 떨어진 곳 이빨 자국 확인 
			if (!mp[a[j] - k] && !mp[a[j] + k]) {
				posi = false;
				break;
			}
		}
		if (posi) {
			cnt++;
			k_arr.push_back(k);
		}
	} 
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) {
		cout << k_arr[i] << " ";
	}
	
	return 0;
}