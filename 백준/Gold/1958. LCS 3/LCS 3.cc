// LCS 3  // dp  // tabulation
#include <iostream>
#include <algorithm>
using namespace std;

int table[101][101][101] = {0, };

int LCS(string str1, string str2, string str3, int n, int m, int l) {
	for (int i = 1; i < n + 1; i++) {
	    for (int j = 1; j < m + 1; j++) {
            for (int k = 1; k < l + 1; k++) {
                if (str1[i-1] == str2[j-1] && str1[i-1] == str3[k-1]) {
				    table[i][j][k] = table[i - 1][j - 1][k - 1] + 1;
			    }
			    else {
				    table[i][j][k] = max(table[i - 1][j][k], max(table[i][j - 1][k], table[i][j][k - 1]));
			    }
            }
        }
	}
	return table[n][m][l];
}

int main() {
	string str1, str2, str3;
	cin >> str1;
	cin >> str2;
    cin >> str3;
	cout << LCS(str1, str2, str3, str1.length(), str2.length(), str3.length()) << "\n";

	return 0;
}