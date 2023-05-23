// dp[n] = dp[n - 1] + dp[n - 2]
// 처음 한 방법보다 더 쉬운 방법 
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> dp(21);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < n; i++) {
		cout << A[i] << "\n";
	}
}