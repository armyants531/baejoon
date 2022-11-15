// 줄세우기  // dp  // LIS
#include <bits/stdc++.h>

using namespace std;

vector<int> length(1000);
vector<int> arr(1000);

int LIS(int n) {
	int max_len = 1;
	for (int x = 0; x < n; x++) { // 인덱스를 한 칸씩 늘려감
		length[x] = 1;
		for (int i = 0; i < x; i++) {
			if (arr[x] > arr[i]) { // x 인덱스의 원소보다 작은 경우
				length[x] = max(length[x], length[i] + 1); // 기존 length[x] 값과 i번째 인덱스에서 끝나는 LIS의 길이 + 1
			}
		}
		max_len = max(max_len, length[x]);
	}
	return max_len;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << N - LIS(N) << "\n";

	return 0;
}