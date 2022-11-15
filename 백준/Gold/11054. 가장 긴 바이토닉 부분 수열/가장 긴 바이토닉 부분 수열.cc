// 가장 긴 바이토닉 부분 수열  // dp  // LIS 변형
#include <bits/stdc++.h>

using namespace std;

vector<int> length1(1000); // i번째 인덱스에서 끝나는 가장 긴 LIS의 길이를 저장하는 리스트
vector<int> length2(1000); // i번째 인덱스에서 시작하는 가장 긴 LIS의 길이를 저장하는 리스트
vector<int> arr(1000);

// Longest Bitonic Subsequence
int LBS(int n) { 
	for (int x = 0; x < n; x++) {
		length1[x] = 1;
		for (int i = 0; i < x; i++) {
			if (arr[x] > arr[i]) {
				length1[x] = max(length1[x], 1 + length1[i]);
			}
		}
	}
	for (int x = n - 1; x >= 0; x--) {
		length2[x] = 1;
		for (int i = n - 1; i > x; i--) {
			if (arr[x] > arr[i]) {
				length2[x] = max(length2[x], 1 + length2[i]);
			}
		}
	}
	int max_length = 1;
	for (int x = 0; x < n; x++) {
		max_length = max(max_length, length1[x] + length2[x] - 1);
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
	cout << LBS(N) << "\n";

	return 0;
}