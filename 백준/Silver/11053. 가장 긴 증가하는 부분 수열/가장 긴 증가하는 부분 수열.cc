// 가장 긴 증가 부분 수열  // dp  // LIS 
#include <bits/stdc++.h>

using namespace std;

vector<int> length(1000); // i번째 인덱스에서 끝나는 가장 긴 증가 부분 수열의 길이을 저장하는 리스트
vector<int> arr(1000);

int LIS(int n) {
	int max_length = 1;
	for (int x = 0; x < n; x++) {
		length[x] = 1;
		for (int i = 0; i < x; i++) {
			if (arr[x] > arr[i]) {
				length[x] = max(length[x], 1 + length[i]);
			}
		}
		max_length = max(max_length, length[x]);
	}
	return max_length;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << LIS(N) << "\n";

	return 0;
}