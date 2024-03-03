#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int max_cnt = 0;
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		cnt += (b-a);
		max_cnt = max(max_cnt, cnt);
	}
	cout << max_cnt << "\n";
	
	return 0;
}