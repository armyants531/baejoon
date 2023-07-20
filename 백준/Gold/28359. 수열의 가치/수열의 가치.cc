#include <bits/stdc++.h>
#define int long long

using namespace std;
vector<string> d;

vector<int> sum(1000);
vector<int> a(1000);

int cal(int n) {
	int max_s = 0;
	int same = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != same) {
			same = a[i];
			sum = a[i]; 
		}
		else {
			sum += a[i];
		}
		max_s = max(max_s, sum);
	}
	return max_s;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	int N;
	cin >> N;
	int s = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		s += a[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	s += cal(N);
	cout << s << "\n";
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}	
	cout << "\n";
	return 0;
}