#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cin.ignore(); // 입력 버퍼에 남아있는 "\n" 제거 
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		cout << i + 1 << ". " << s << "\n";
	}
	
	return 0;
}