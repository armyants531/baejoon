// 부분합  // two pointer
// https://wadekang.tistory.com/5 참고
#include <bits/stdc++.h>

using namespace std;

int min_len(vector<long long> arr, int N, int S) {
	int low = 0, high; // low, high pointer
	long long sum = 0;
	int len = 100000; // (10 ≤ N < 100,000)
	for (high = 0; high < N; high++) { // high를 오른쪽으로 이동
		sum += arr[high];
		while (sum >= S && low <= high) { // sum이 S이상이고 low가 high이하이면
			len = min(len, high - low + 1); // 길이 비교
			sum -= arr[low]; // low를 오른쪽으로 이동
			low++;
		}
	}
	if (len == 100000) {
		return 0;
	}
	else {
		return len;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	long long S, val;
	vector<long long> arr;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> val;
		arr.push_back(val);
	}
	cout << min_len(arr, N, S) << "\n";
}