#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<pair<int, int>> arr;
	for (int i = 0; i < N; i++) {
		int d, t;
		cin >> d >> t;
		arr.push_back({d, t});
	}
	sort(arr.begin(), arr.end());
	bool posi = true;
	int preSum = 0;
	int preSum2 = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		preSum += arr[i].second;
		preSum2 += arr[i].second;
		int date = arr[i].first - arr[i].first / 7 * 2;
		if (arr[i].first % 7 == 6) {
			date -= 1;
		}
		
		cnt += max(preSum2 - date, 0);
		//cout << preSum2 << " ";
		preSum2 = min(date, preSum2);
		int max_d = arr[i].first * 2;
		max_d -= arr[i].first / 7 * 2;
		if (arr[i].first % 7 == 6) {
			max_d -= 1;
		}
		if (max_d < preSum) {
			posi = false;
			break;
		}
	}
	if (posi) {
		cout << cnt << "\n";
	}
	else {
		cout << -1 << "\n";
	}
	
	return 0;
}