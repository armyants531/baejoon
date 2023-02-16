#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> arr(1000001);
	deque<int> dq;
	int t;
	for (int i = 1; i <= N; i++) {
		cin >> t;
		arr[t] = 1;
	}
	bool can = true;
	//cout << t << "\n";
	for (int i = 0; i <= t; i++) {
		if (arr[i] == 0) {
			dq.push_back(i);
		}
	}
	// 커피 처리
	deque<int> dq2;
	for (int i = t; i >= 0; i--) {
		if (arr[i] == 1) { // 손님이 오는 시간	
			while (!dq.empty() && dq.back() >= i) { // dq.back() < i 일 때 까지
				dq2.push_front(dq.back());
				dq.pop_back();
			}
			if (!dq.empty() && dq.back() + M >= i) {
				//cout << dq.back() << "\n";
				dq.pop_back();
			}
			else {
				can = false;
				break;
			}
		}
	}
	while (!dq2.empty()) {
		dq.push_back(dq2.front());
		dq2.pop_front();
	}

	// 토기 처리
	for (int i = 0; i <= t; i++) {
		if (arr[i] == 1) { // 손님이 오는 시간
			if (!dq.empty() && dq.front() < i) {
				//cout << dq.front() << "\n";
				dq.pop_front();
			}
			else {
				can = false;
				break;
			}
		}
	}
	if (can) {
		cout << "success" << "\n";
	}
	else {
		cout << "fail" << "\n";
	}
}