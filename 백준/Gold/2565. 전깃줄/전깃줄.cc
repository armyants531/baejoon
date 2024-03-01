#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> a;
vector<int> dp; // i번 째 인덱스에서 끝나는 LIS의 길이 

int LIS(int n) {
	int max_len = 1;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}	
		max_len = max(max_len, dp[i]);
	}
	
	return max_len;
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	dp.resize(n);
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		//cout << v[i].first << " " << v[i].second << "\n";
		a.push_back(v[i].second);
	}
	cout << n - LIS(n) << "\n";
	return 0;
}