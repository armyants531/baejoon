// 수들의 합 2  // two pointer
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, cnt = 0;
	long long M, val, sum = 0;
	vector<long long> arr;
	cin >> N >> M;
	int low = 0, high; // low, high pointer
	for (high = 0; high < N; high++) {
		cin >> val;
		arr.push_back(val);
		sum += val;
		while (sum > M && low <= high) { // sum이 M 보다 크고 low가 high 이하이면
			sum -= arr[low]; // low를 오른쪽으로 이동
			low++;
		}
		if (sum == M) {
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}