// 계단 오르기  // tabulation
// 점화식 sum[n] = max(sum[n-3] + arr[n-1] + arr[n], sum[n-2] + arr[n])
#include <iostream>
#include <algorithm> // max

using namespace std;

long long arr[300];
long long sum[300];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n == 1)
		cout << arr[0] << "\n";
	else if (n == 2)
		cout << arr[0] + arr[1] << "\n";
	else if (n == 3)
		cout << max(arr[1], arr[0]) + arr[2] << "\n";
	else {
		sum[0] = arr[0]; // 1개의 계단
		sum[1] = arr[0] + arr[1]; // 2개의 계단
		sum[2] = max(arr[1], arr[0]) + arr[2]; // 3개의 계단
		for (int i = 3; i < n; i++) {
			sum[i] = max(sum[i - 3] + arr[i - 1], sum[i - 2]) + arr[i];
		}
		cout << sum[n - 1] << "\n";
	}
}