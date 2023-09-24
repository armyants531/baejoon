#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

struct dpq {
	int diff, p, q;
};

bool cmp(dpq A, dpq B) {
	return A.diff > B.diff;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	string s;
	cin >> N >> s;
	vector<int> a0(N), a1(N), a2(N);
	for (int i = 0; i < N; i++) {
		if (s[i] == 'R') {
			a0[i] = 0;	
			a1[i] = 0;
			a2[i] = 0;
		}
		else if (s[i] == 'G') {
			a0[i] = 1;
			a1[i] = 1;
			a2[i] = 1;
		}
		else { // 'B'
			a0[i] = 2;
			a1[i] = 2;
			a2[i] = 2;
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		cout << a0[i];
	}
	cout << "\n";
	*/
	int cnt0 = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < N - 2; i++) {
		while (a0[i] != 0) {
			a0[i]++;
			a0[i] %= 3;
			a0[i + 1]++;
			a0[i + 1] %= 3;
			a0[i + 2]++;
			a0[i + 2] %= 3;	
			cnt0++;
		}
	}
	if (a0[N - 2] != 0 || a0[N - 1] != 0) {
		cnt0 = 200001;
	}
	for (int i = 0; i < N - 2; i++) {
		while (a1[i] != 1) {
			a1[i]++;
			a1[i] %= 3;
			a1[i + 1]++;
			a1[i + 1] %= 3;
			a1[i + 2]++;
			a1[i + 2] %= 3;	
			cnt1++;				
		}
	}
	if (a1[N - 2] != 1 || a1[N - 1] != 1) {
		cnt1 = 200001;
	}
	for (int i = 0; i < N - 2; i++) {
		while (a2[i] != 2) {
			a2[i]++;
			a2[i] %= 3;
			a2[i + 1]++;
			a2[i + 1] %= 3;
			a2[i + 2]++;
			a2[i + 2] %= 3;	
			cnt2++;			
		}
	}
	if (a2[N - 2] != 2 || a2[N - 1] != 2) {
		cnt2 = 200001;
	}
	int cnt = min({cnt0, cnt1, cnt2});
	if (cnt == 200001) {
		cout << -1 << "\n";
	}
	else {
		cout << cnt << "\n";
	}
	
	return 0;
}