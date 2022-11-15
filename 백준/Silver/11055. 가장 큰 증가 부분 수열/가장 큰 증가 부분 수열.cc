// 가장 큰 증가 부분 수열  // dp  // LIS 변형
#include <bits/stdc++.h>

using namespace std;

vector<int> sum(1000); // i번째 인덱스에서 끝나는 가장 큰 증가 부분 수열의 합을 저장하는 리스트
vector<int> arr(1000);

int dp(int n) {
	int max_sum = 0;
	for (int x = 0; x < n; x++) {
		sum[x] = arr[x];
		for (int i = 0; i < x; i++) {
			if (arr[x] > arr[i]) {
				sum[x] = max(sum[x], arr[x] + sum[i]);
			}
		}
		max_sum = max(max_sum, sum[x]);
	}
	return max_sum; 
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
	cout << dp(N) << "\n";

	return 0;
}