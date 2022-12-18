#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; 
	cin >> N;
	string s;
	cin >> s;
	int scnt = 0;
	int bcnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 's') {
			scnt++;
		}
		else if (s[i] == 'b') {
			bcnt++;
		}
	}
	if (scnt > bcnt) {
		cout << "security!" << "\n";
	}
	else if (scnt < bcnt) {
		cout << "bigdata?" << "\n";
	}
	else {
		cout << "bigdata? security!" << "\n";
	}
}