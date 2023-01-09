#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	map<int, int> mp;
	set<int> peo;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (mp[a] == b + 1) {
			cnt++;
		}
		else if (b == 0 && mp[a] != 2) { // 들어가지 않음 -> 나옴
			cnt++;
		}
		peo.insert(a);
		mp[a] = b + 1;
	}
	for (set<int>::iterator iter = peo.begin(); iter != peo.end(); iter++) {
		if (mp[*iter] == 2) {
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}