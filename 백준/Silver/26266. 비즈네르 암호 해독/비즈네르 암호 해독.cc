#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string A, B;
	cin >> A >> B;
	string arr = "";
	for (int i = 0; i < A.size(); i++) {
		int c = (int)(B[i] - 'A') - (int)(A[i] - 'A');
		if (c <= 0) {
			c += 26;
		}
		char ch = (char)('A' + c - 1);
		arr += ch;
	}
	string s = "";
	for (int i = 0; i < A.size(); i++) {
		s += arr[i];
		if (arr.size() % (i + 1)) {
			continue;
		}
		int cnt = arr.size() / (i + 1);
		string temp = "";
		for (int j = 0; j < cnt; j++) {
			temp += s;
		}
		if (temp == arr) {
			cout << s << "\n";
			break;
		}
	}
}