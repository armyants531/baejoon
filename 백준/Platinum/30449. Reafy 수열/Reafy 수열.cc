#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef long long ll;
vector<pair<int, int>> s;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	// (double)a.fi / (double)a.se < (double)b.fi / (double)b.se;
	int A = a.fi * b.se;
	int B = a.se * b.fi;
	return A < B; // 오름차순
}

int gcd(int a, int b) {
    return b % a == 0 ? a : gcd(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	s.push_back({0, 1});
	
	for (int a = 1; a <= n / 2; a++) {
		for (int b = a * 2; b <= n; b++) { // 1/2 이하인 것만 넣어주기 		
			if (gcd(a, b) == 1) s.push_back({a, b}); 
		}
	}
	//cout << s.size() << "\n";
	if (k <= s.size()) {
		nth_element(s.begin(), s.begin() + k - 1, s.end(), cmp); // quickselect alg
		cout << s[k - 1].fi << " " << s[k - 1].se << "\n";
	}
	else {
		int idx = s.size() * 2 - 1 - k;
		nth_element(s.begin(), s.begin() + idx, s.end(), cmp);
		cout << s[idx].se - s[idx].fi << " " << s[idx].se << "\n";
	}
	
	return 0;
}