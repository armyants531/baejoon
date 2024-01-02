#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> a(5);
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 1; i < 5; i++) {
		if (a[0] - a[i] <= 1000) cnt++;
		else break;
	}
	cout << cnt << "\n";
	return 0;
}