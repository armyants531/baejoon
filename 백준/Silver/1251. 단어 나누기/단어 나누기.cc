#include <bits/stdc++.h>
#define fi first
#define se second
#define INF 2000000000
#define int long long
using namespace std;

using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int N = s.size();
	vector<string> a;
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			string s1, s2, s3;
			s1 = s.substr(0, i);
			s2 = s.substr(i, j-i);
			s3 = s.substr(j, N-j);
			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			reverse(s3.begin(), s3.end());
			a.push_back(s1 + s2 + s3);
		}
	}
	sort(a.begin(), a.end());
	cout << a[0] << "\n";
	
	return 0;
}