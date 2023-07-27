#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

bool cmp(pii a, pii b) {
	if (a.first == b.first) {
		return a.second < b.second; // 인덱스가 작은 순 
	}
	return a.first > b.first; // 선물이 많은 순 
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<pii> a;
	vector<pii> b;
	int max_i = -1;
	int max_a = -1;
	for (int i = 1; i <= N; i++) {
		pii p;
		cin >> p.first;
		p.second = i;
		a.push_back(p);
	}
	sort(a.begin(), a.end(), cmp); 
	for (int i = 1; i <= N; i++) {
		pii p;
		cin >> p.first;
		if (a[0].second == i) {
			continue;
		}
		p.second = i;
		b.push_back(p);	
	}
	sort(b.begin(), b.end());
	vector<pii> plus;
	vector<pii> plus2;
	// 가장 많은 선물 가진 부원에게 선물 모두 넘기기 
	for (int i = 1; i < N; i++) {
		if (a[i].first != 0) {
			plus.push_back({ a[0].second, a[i].first });
		}
	}
	// 재분배(적게 필요한 순으로)
	for (int i = 0; i < N - 1; i++) {
		if (b[i].first != 0) {
			plus2.push_back({ b[i].second, b[i].first });
		}
	}
	cout << plus.size() + plus2.size() << "\n";
	for (int i = 0; i < plus.size(); i++) {
		cout << "+ " << plus[i].first << " " << plus[i].second << "\n";
	}
	for (int i = 0; i < plus2.size(); i++) {
		cout << "+ " << plus2[i].first << " " << plus2[i].second << "\n";
	}
	
	return 0;
}