#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef long long ll;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	deque<int> dq;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	while (dq.size() >= 2) {
		dq.pop_front();
		int t = dq.front();
		dq.pop_front();
		dq.push_back(t);
	} 
	cout << dq.front() << "\n";
	
	return 0;
}