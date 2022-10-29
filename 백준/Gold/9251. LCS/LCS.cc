#include <iostream>
#include <algorithm>
using namespace std;

int table[1001][1001] = {0, };

// tabulation
int LCS(string str1, string str2, int n, int m) {
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (str1[i-1] == str2[j-1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else {
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
		}
	}
	return table[n][m];
}

int main() {
	string str1, str2;
	cin >> str1;
	cin >> str2;
	cout << LCS(str1, str2, str1.length(), str2.length()) << "\n";

	return 0;
}