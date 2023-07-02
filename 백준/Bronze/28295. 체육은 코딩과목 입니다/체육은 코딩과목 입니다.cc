#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string s = "NESW";
	int idx = 0;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		idx += n;
	}
	idx %= 4;
	cout << s[idx] << "\n";
	return 0;	
}