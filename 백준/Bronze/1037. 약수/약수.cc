#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << a[0] * a[N - 1] << "\n";
	
	return 0;
}