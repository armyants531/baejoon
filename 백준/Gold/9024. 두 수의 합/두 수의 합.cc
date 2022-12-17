// 두 수의 합  // two pointer
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		int low = 0;
		int high = n - 1;
		int cnt = 0;
		int closest = arr[low] + arr[high];
		while (low < high) {
			int sum = arr[low] + arr[high];
			if (sum == k) { // k와 일치하는 경우
				if (closest != k) {
					cnt = 0; // cnt 갱신
					closest = k; // closest 갱신
				}
				cnt++;
				// arr에는 서로 다른 정수로 이루어져 있으므로 low, high 모두 줄인다
				high--;
				low++;
			}
			else if (sum > k) { // k 보다 큰 경우
				if (sum - k == abs(closest - k)) { // k와의 차이가 같으면
					cnt++;
				}
				else if (sum - k < abs(closest - k)) { // k와의 차이가 더 작으면 
					cnt = 1; // cnt 갱신
					closest = sum; // closest 갱신
				}
				high--;
			}
			else { // sum < k
				if (k - sum == abs(closest - k)) {
					cnt++;
				}
				else if (k - sum < abs(closest - k)) {
					cnt = 1;
					closest = sum;
				}
				low++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}