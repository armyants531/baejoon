// 플래피 버드 스코어링  // binary search
#include <bits/stdc++.h>

using namespace std; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(N);
	
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		arr[i] = val;
	}
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		arr[i] -= val;
	}
	for (int i = 1; i < N; i++) {
		arr[i] = min(arr[i - 1], arr[i]); // 앞선 것과 비교해 최소인 것으로 바꾸어줌
	}
	reverse(arr.begin(), arr.end());

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int val;
		cin >> val;
		int idx = lower_bound(arr.begin(), arr.end(), val) - arr.begin();
		cout << N - idx << "\n";
	}
}