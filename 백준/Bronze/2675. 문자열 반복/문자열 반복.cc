#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int repeat;
		string s;
		cin >> repeat >> s;
		for (int j = 0; j < s.length(); j++) {
			for (int k = 0; k < repeat; k++) 
				cout << s[j];
		}
		cout << "\n";
	}
	return 0;
}