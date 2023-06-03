#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	stack<int> st;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a == 0) {
			st.pop();
		}
		else {
			st.push(a);
		} 
	}
	ll sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum << "\n";
}