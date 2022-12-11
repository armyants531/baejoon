// 숫자 카드 2  // 이분 탐색
#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		// 처음으로 초과하는 수의 인덱스 - 처음으로 같거나 큰 수의 인덱스 
		cout << upper_bound(arr.begin(), arr.end(), num) - lower_bound(arr.begin(), arr.end(), num) << " ";
	}
	cout << "\n";

	return 0;
}