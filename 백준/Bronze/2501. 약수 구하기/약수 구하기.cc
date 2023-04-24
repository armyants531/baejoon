#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	int cnt = 0;
	bool ex = false;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			cnt++;
		} 
		if (cnt == K) {
			ex = true;
			cout << i << "\n";
			break;
		}
	}
	if (!ex) {
		cout << 0 << "\n";
	}
	
	return 0;
}