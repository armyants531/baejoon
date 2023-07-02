#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	vector<int> A(4);
	string s = "NESWNESWNESW";
	for (int i = 0; i < 10; i++) {
		cin >> n;
		A[n]++;
	}
	A[2] %= 2;
	A[1] %= 4;
	A[3] %= 4;
	int idx = 4;
	if (A[1] > A[3]) {
		idx += A[1] - A[3];
	}
	else {
		idx -= A[3] - A[1];
	}
	if (A[2]) {
		idx += 2;
	}
	cout << s[idx] << "\n";
	return 0;	
}