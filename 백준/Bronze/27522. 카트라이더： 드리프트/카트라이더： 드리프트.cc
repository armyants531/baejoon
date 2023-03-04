#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	char team;
	vector<pair<int, char>> arr;
	for (int i = 0; i < 8; i++) {
		cin >> s >> team;
		int time = (s[0] - '0') * 60 * 1000 + (s[2] - '0') * 10000 + (s[3] - '0') * 1000 + (s[5] - '0') * 100 + (s[6] - '0') * 10 + (s[7] - '0');
		arr.push_back({time, team});
	}
	sort(arr.begin(), arr.end());
	int A = 0;
	int B = 0;
	vector<int> point = { 10, 8, 6, 5, 4, 3, 2, 1 };
	for (int i = 0; i < 8; i++) {
		if (arr[i].second == 'R') {
			A += point[i];
		}
		else {
			B += point[i];
		}
	}
	if (A > B) {
		cout << "Red";
	}
	else {
		cout << "Blue";
	}
}