
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	deque<int> dq;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num, x;
		cin >> num;
		if (num == 1) {
			cin >> x;
			dq.push_front(x); 
		}
		else if (num == 2) {
			cin >> x;
			dq.push_back(x); 
		}
		else if (num == 3) {
			if (!dq.empty()) {
				int a = dq.front();
				dq.pop_front();
				cout << a << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (num == 4) {
			if (!dq.empty()) {
				int b = dq.back();
				dq.pop_back();
				cout << b << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (num == 5) {
			cout << dq.size() << "\n";
		}
		else if (num == 6) {
			if (dq.empty())	{
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (num == 7) {
			if (!dq.empty()) {
				cout << dq.front() << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
		else {
			if (!dq.empty()) {
				cout << dq.back() << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
	}
}