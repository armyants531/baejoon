// 큐 2
#include <bits/stdc++.h>

using namespace std;

queue<int> que;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; 
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int val;
			cin >> val;
			que.push(val);
		}
		else if (str == "pop") {
			if (que.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << que.front() << "\n";
				que.pop();
			}
		}
		else if (str == "size") {
			cout << que.size() << "\n";
		}
		else if (str == "empty") {
			cout << (que.empty() ? 1 : 0) << "\n";
		}
		else if (str == "front") {
			if (que.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << que.front() << "\n";
			}
		}
		else if (str == "back") {
			if (que.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << que.back() << "\n";
			}
		}
	}

	return 0;
}