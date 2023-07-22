#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef long long ll;

vector<int> checker;

int sol(vector<int> mat, int N) {
	int cnt = 0;
	bool flag = true;
	for (int i = 0; i < N; i++) {
		if (mat[i] > checker[i]) {
			for (int j = i + 1; j < N; j++) {
				if (mat[j] <= checker[i]) {
					for (int k = j; k > i; k--) {
						swap(mat[k], mat[k - 1]);
						cnt++;
					}
					break;
				}
			}
		}
	}
	return cnt;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < 40; i++) {
		checker.push_back(i + 1);
	}
	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		vector<int> mat;
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			int right_most = 0;
			for (int j = s.size() - 1; j >= 0; j--) {
				if (s[j] == '1') {
					right_most = j + 1;
					break;
				}
			}
			mat.push_back(right_most);
		}
		cout << "Case #" << t << ": " << sol(mat, N) << "\n";
	}

	return 0;
}