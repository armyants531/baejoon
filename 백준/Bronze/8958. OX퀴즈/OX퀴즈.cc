#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int point = 0;
		int accum = 0;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'O') {
				accum++;
				point += accum;
			}
			else {
				accum = 0;
			}
		}
		cout << point << "\n";
	}
}