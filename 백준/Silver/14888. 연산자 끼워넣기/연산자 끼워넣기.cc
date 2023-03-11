// 연산자 끼워넣기  // backtracking
#include <bits/stdc++.h>

using namespace std;

vector<int> arr(11);
vector<string> expre;

void dfs(int sum, int min, int mul, int div, string ex) {
	if (sum == 0 && min == 0 && mul == 0 && div == 0) {
		expre.push_back(ex);
		return;
	}
	if (sum > 0) {
		dfs(sum - 1, min, mul, div, ex + "+");
	}
	if (min > 0) {
		dfs(sum, min - 1, mul, div, ex + "-");
	}
	if (mul > 0) {
		dfs(sum, min, mul - 1, div, ex + "*");
	}
	if (div > 0) {
		dfs(sum, min, mul, div - 1, ex + "%");
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int sum, cha, mul, div;
	cin >> sum >> cha >> mul >> div;
	
	dfs(sum, cha, mul, div, "");
	/*
	for (int i = 0; i < expre.size(); i++) {
		cout << expre[i] << "\n";
	}
	*/
	int minRe = 1000000001;
	int maxRe = -1000000001;
	for (int i = 0; i < expre.size(); i++) {
		int result = arr[0];
		for (int j = 0; j < expre[i].size(); j++) {
			if (expre[i][j] == '+') {
				result += arr[j + 1];
			}
			else if (expre[i][j] == '-') {
				result -= arr[j + 1];
			}
			else if (expre[i][j] == '*') {
				result *= arr[j + 1];
			}
			else {
				result /= arr[j + 1];
			}
		}
		minRe = min(minRe, result);
		maxRe = max(maxRe, result);
	}
	cout << maxRe << "\n";
	cout << minRe << "\n";
}