// 히스토그램  // stack
// https://sgc109.github.io/2021/03/18/largest-rectangle-in-histogram/ 참고
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> arr;
stack<int> st;

ll sol() {
	arr.push_back(-7); // 마지막에 계산을 해주기 위해 최소 높이보다 작은 값을 넣어줌
	st.push(-1);
	ll area = 0;
	for (int i = 0; i < arr.size(); i++) {
		while (st.size() >= 2 && arr[st.top()] > arr[i]) {
			int idx_h = st.top(); // 직사각형의 높이가 되는 arr 원소의 인덱스 
			st.pop();
			int idx_left = st.top(); // 직사각형의 왼쪽 인덱스
			area = max(area, ((i - 1) - idx_left) * arr[idx_h]); // i - 1: 직사각형의 오른쪽 인덱스
		}
		st.push(i);
	}
	return area;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int height;
		cin >> height;
		arr.push_back(height);
	}
	cout << sol() << "\n";

	return 0; 
}