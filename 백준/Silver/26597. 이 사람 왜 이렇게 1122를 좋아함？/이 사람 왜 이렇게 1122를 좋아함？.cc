#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Q;
	cin >> Q;
	int paradox = -1;
	int canknow = -1;
	ll start = -1000000000000000001;
	ll end = 1000000000000000001;
	for (int i = 1; i <= Q; i++)
	{
		ll x;
		char c;
		cin >> x >> c;
		if (c == '^') {
			start = max(start, x);
		}
		else {
			end = min(end, x);
		}
		if (paradox == -1 && start + 1 >= end) {
			paradox = i;
		}
		else if (canknow == -1 && start + 2 == end) {
			canknow = i;
		}
	}
	if (paradox != -1) {
		cout << "Paradox!" << "\n";
		cout << paradox << "\n";
	}
	else if (canknow != -1) {
		cout << "I got it!" << "\n";
		cout << canknow << "\n";
	}
	else {
		cout << "Hmm..." << "\n";
	}
	return 0;
}