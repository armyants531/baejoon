// 포스택  // greedy
// 네 개의 배열(스택)에 오름차순으로 순열의 원소를 모두 넣을 수 있는지 판단하면 된다. 
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr;
	stack<int> st1, st2, st3, st4;
	// 처음에는 0이하의 서로 다른 정수를 스택에 하나씩 넣어줌 
	st1.push(0); st2.push(-1); st3.push(-2); st4.push(-3); // 가장 큰 원소는 앞으로 st1에 들어감
	int val;
	bool isPossible = true;
	for (int i = 0; i < N; i++) {
		cin >> val;
		// val보다 작은 top을 가진 스택 중 top 값이 가장 큰 스택에 val을 push
		// top1 > top2 > top3 > top4를 계속 유지
		int top1 = st1.top();
		int top2 = st2.top();
		int top3 = st3.top();
		int top4 = st4.top();
		if (top1 < val && top2 < val && top3 < val && top4 < val) {
			st1.push(val);
		}
		else if (top2 < val && top3 < val && top4 < val) {
			st2.push(val);
		}
		else if (top3 < val && top4 < val) {
			st3.push(val);
		}
		else if (top4 < val) {
			st4.push(val);
		}
		else { // top중 val보다 작은 값이 없을 때
			isPossible = false;
			break;
		}
	}
	if (isPossible) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}

	return 0;
}