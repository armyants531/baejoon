#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	int n, m;
	cin >> n >> m;
	ll a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		pq.push(a);
	}
	for (int i = 0; i < m; i++) {
		ll x = pq.top();
		pq.pop();
		ll y = pq.top();
		pq.pop();
		pq.push(x + y);
		pq.push(x + y);
	} 
	ll sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum << "\n";
	
	return 0;
}