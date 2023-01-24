// 2023년이 기대되는 이유  // backtracking
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<vector<vector<int>>> table(9);

int count(vector<int> arr) {
	int len = arr.size();
	bool all01 = true; // 모두 0과 1로만 이루어져 있는가?
	for (int i = 0; i < len; i++) {
		if (arr[i] != 0 && arr[i] != 1) {
			all01 = false;
			break;
		}
	}
	if (all01) {
		return 987654321;
	}
	if (len == 1) {
		return 1;
	}
	else {
		ll left = 0;
		ll right = 0;
		set<int> set_m;
		for (int i = 0; i < table[len - 2].size(); i++) { // 모든 경우에 대해
			// right 계산
			int temp = arr[0];
			bool wrong_case = false;
			for (int j = 0; j < table[len - 2][i].size(); j++) {
				if (table[len - 2][i][j] == 1) {
					if (arr[j + 1] == 0 && len > j + 2 && table[len - 2][i][j + 1] == 0) { // 0으로 시작되는 수를 더하는 경우(ex: 2 + 05)
						wrong_case = true;
						break;
					}
					right += temp;
					temp = arr[j + 1];
				}
				else {
					temp *= 10;
					temp += arr[j + 1];
				}
			}
			right += temp; // 마지막에 temp를 더해줌
			if (wrong_case) {
				right = 0;
				continue;
			}
			//cout << "right:" << " " << right << "\n";
			// left와 right 비교
			int m = 1;
			left = 0;
			while (left <= right) {
				left = 0;
				for (int j = 0; j < len; j++) {
					left += pow(arr[j], m);
				}
				if (left == right) {
					/*
					for (int k = 0; k < table[len - 2][i].size(); k++) {
						cout << table[len - 2][i][k] << " ";
					}
					cout << "\n";
					cout << "left:" << " " << left << "\n";
					*/
					set_m.insert(m);
					break;
				}
				m++;
			}
			right = 0; // right 초기화
		}
		int cnt = set_m.size();
		return cnt;
	}
}

void dfs(int x, vector<int> arr) {
	if (arr.size() == x + 1) {
		table[x].push_back(arr);
		return;
	}
	vector<int> arr2 = arr;
	arr2.push_back(0); // '+' 안 넣음
	dfs(x, arr2);
	arr2.pop_back();
	arr2.push_back(1); // '+' 넣음
	dfs(x, arr2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	// '+' 넣는 경우를 전처리
	for (int i = 0; i < 9; i++) {
		vector<int> arr;
		dfs(i, arr);
	}
	/*
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < table[i].size(); j++) {
			for (auto a : table[i][j]) {
				cout << a << " ";
			}
			cout << "\n";
		}
	}
	*/
	
	for (int i = 0; i < T; i++) {
		string n;
		cin >> n;
		vector<int> arr;
		for (int j = 0; j < n.size(); j++) {
			arr.push_back((int)(n[j] - '0'));
		}
		int ans = count(arr);
		if (ans == 987654321) {
			cout << "Hello, BOJ 2023!" << "\n";
		}
		else {
			cout << ans << "\n";
		}
	}
	return 0;
}