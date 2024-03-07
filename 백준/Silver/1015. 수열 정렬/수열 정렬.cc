#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}  
	for (int i = 0; i < N; i++) {
		v[i] = {A[i], i};
	}
	sort(v.begin(), v.end());
	vector<pair<int, int>> v2(N);
	for (int i = 0; i < N; i++) {
		v2[i] = {v[i].second, i};
	}
	sort(v2.begin(), v2.end());
	for (int i = 0; i < N; i++) {
		cout << v2[i].second << " ";
	}
	
	return 0;
}