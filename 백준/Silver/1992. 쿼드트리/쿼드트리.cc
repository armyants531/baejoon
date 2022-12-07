// 쿼드트리  // 분할 정복
#include <bits/stdc++.h>

using namespace std;

vector<string> arr;

void sol(int y, int x, int len) {
	char num = arr[y][x];
	for (int i = y; i < y + len; i++) {
		for (int j = x; j < x + len; j++) {
			if (num != arr[i][j]) {
				len /= 2;
				cout << '(';
				sol(y, x, len);
				sol(y, x + len, len);
				sol(y + len, x, len);
				sol(y + len, x + len, len);
				cout << ')';
				return; // end
			}
		}
	}
	if (num == '0') {
		cout << 0;
	}
	else {
		cout << 1;
	}
}

int main() {
	int N;
	cin >> N;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		arr.push_back(str);
	}
	sol(0, 0, N);

	return 0;
}