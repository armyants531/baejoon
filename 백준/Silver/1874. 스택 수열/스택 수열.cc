// 스택 수열  // data structure  // stack
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	stack<int> st;
	vector<char> arr;
	vector<int> input_arr;
	cin >> n;
	int t = 0;
	int val;
	bool possible = true;
	input_arr.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> val; 
		input_arr.push_back(val);
		if (val > input_arr[i]) { // 현재의 input값이 이전 input 값보다 크면
			for (int j = t + 1; j <= val; j++) { // t+1부터 val까지 스택에 push
				st.push(j);
				arr.push_back('+');
			}
			t = val; // t값을 input값으로 갱신
		}
		if (st.empty() || val != st.top()) { // 스택이 비었거나 input 값이 stack의 top과 다르면 
			possible = false;
		}
		arr.push_back('-');
		st.pop();
	}

	if (!possible) {
		cout << "NO" << "\n";
	}
	else {
		for (int i = 0; i < 2 * n; i++) {
			cout << arr[i] << "\n";
		}
	}
}