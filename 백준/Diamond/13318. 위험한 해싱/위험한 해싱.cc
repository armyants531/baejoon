#include <bits/stdc++.h>
#define int long long
#define p 1000000007

using namespace std;
typedef long long ll;

vector<int> arr(300001);

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<vector<int>> m = { {1974, 25112, 0}, {4940, 24615, 0}, {9257, 22726, 0}, {4471, 15566, 0},
		{11801, 22207, 0}, {21176, 24624, 0}, {5862, 6835, 0}, {32709, 33094, 0},
		{12611, 37036, 0}, {6484, 30660, 0} }; // 지수
	vector<vector<int>> s = { {1,1,-1}, {1,1,1}, {1,1,1}, {1,-1,-1}, {1,-1,-1}, {1,1,-1}, {1,1,-1}, {1,1,-1}, {1,-1,1}, {1,-1,1} }; // 부호
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++) {
			for (int c = 0; c < 3; c++) {
				for (int d = 0; d < 3; d++) {
					for (int e = 0; e < 3; e++) {
						for (int f = 0; f < 3; f++) {
							for (int g = 0; g < 3; g++) {
								for (int h = 0; h < 3; h++) {
									for (int i = 0; i < 3; i++) {
										for (int j = 0; j < 3; j++) {
											int sum = m[0][a] + m[1][b] + m[2][c] + m[3][d] + m[4][e] + m[5][f] + m[6][g] + m[7][h] + m[8][i] + m[9][j];
											//cout << sum << "\n";
											int sign = s[0][a] * s[1][b] * s[2][c] * s[3][d] * s[4][e] * s[5][f] * s[6][g] * s[7][h] * s[8][i] * s[9][j];
											arr[sum] += sign;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	string a = "";
	string b = "";
	/*
	for (int i = 300000; i >= 0; i--) {
		if (arr[i]) {
			cout << i << "\n"; // 242475
			break;
		}
	}
	*/
	//vector<int> A(242476);
	//vector<int> B(242476);
	for (int i = 0; i <= 242475; i++) {
		if (arr[i] == 0) {
			a += 'a';
			b += 'a';
		}
		else if (arr[i] == 1) {
			a += 'b';
			b += 'a';

		}
		else if (arr[i] == -1) {
			a += 'a';
			b += 'b';
		}
		else if (arr[i] == 2) {
			a += 'c';
			b += 'a';
		}
		else if (arr[i] == -2) {
			a += 'a';
			b += 'c';
		}
		else if (arr[i] == 3) {
			a += 'd';
			b += 'a';
		}
		else if (arr[i] == -3) {
			a += 'a';
			b += 'd';
		}
		else if (arr[i] == 4) {
			a += 'e';
			b += 'a';
		}
		else if (arr[i] == -4) {
			a += 'a';
			b += 'e';
		}
		//cout << arr[i] << " ";
	}
	cout << a << "\n" << b << "\n";

	return 0;
}