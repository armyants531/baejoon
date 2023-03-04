#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	deque<char> dq;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int ord;
		cin >> ord;
		if (ord == 1) {
			char c;
			cin >> c;
			dq.push_back(c);
			arr.push_back(1);
		}
		else if (ord == 2) {
			char c;
			cin >> c;
			dq.push_front(c);
			arr.push_back(0);
		}
		else {
			if (arr.empty()) continue;
			if (arr.back() == 1) {
				dq.pop_back();
				arr.pop_back();
			}
			else {
				dq.pop_front();
				arr.pop_back();
			}
		}
	}
	if (dq.empty()) {
		cout << 0;
	}
	else {
		for (int i = 0; i < dq.size(); i++) {
			cout << dq[i] << "";
		}
	}
}