#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	vector<int> arr(7);
	int a, b, c;
	cin >> a >> b >> c;
	arr[a]++;
	arr[b]++;
	arr[c]++;
	int max_val = 0;
	if (s[0] == 'Y') {
		int sum = 2;
		sum += arr[1];
		max_val = max(max_val, sum);
	}
	if (s[1] == 'Y') {
		int sum = 4;
		sum += arr[2] * 2;
		max_val = max(max_val, sum);
	}
	if (s[2] == 'Y') {
		int sum = 6;
		sum += arr[3] * 3;
		max_val = max(max_val, sum);
	}
	if (s[3] == 'Y') {
		int sum = 8;
		sum += arr[4] * 4;
		max_val = max(max_val, sum);
	}
	if (s[4] == 'Y') {
		int sum = 10;
		sum += arr[5] * 5;
		max_val = max(max_val, sum);
	}
	if (s[5] == 'Y') {
		int sum = 12;
		sum += arr[6] * 6;
		max_val = max(max_val, sum);
	}
	if (s[6] == 'Y') { // Four of a Kind
		int sum = 0;
		for (int i = 1; i <= 6; i++) {
			if (arr[i] >= 2) {
				sum = 4 * i;
			}
		}
		max_val = max(max_val, sum);
	}
	if (s[7] == 'Y') { // Full House
		int sum = 0;
		if (a == b && b == c) {
			if (a == 6) {
				sum = 18 + 10;
			}
			else {
				sum = a * 3 + 12;
			}
		}
		else if (a == b) {
			if (a > c) {
				sum = a * 3 + c * 2;
			}
			else {
				sum = c * 3 + a * 2;
			}
		}
		else if (b == c) {
			if (c > a) {
				sum = c * 3 + a * 2;
			}
			else {
				sum = a * 3 + c * 2;
			}
		}
		else if (c == a) {
			if (b > a) {
				sum = b * 3 + a * 2;
			}
			else {
				sum = a * 3 + b * 2;
			}
		}
		max_val = max(max_val, sum);
	}
	if (s[8] == 'Y') { // Little Straight
		int sum = 0;
		if (a != b && b != c && c != a && arr[6] == 0) {
			sum = 30;
		}
		max_val = max(max_val, sum);
	}
	if (s[9] == 'Y') { // Big Straight
		int sum = 0;
		if (a != b && b != c && c != a && arr[1] == 0) {
			sum = 30;
		}
		max_val = max(max_val, sum);
	}
	if (s[10] == 'Y') { // Yacht
		int sum = 0;
		if (a == b && b == c) {
			sum = 50;
		}
		max_val = max(max_val, sum);
	}
	if (s[11] == 'Y') { // Choice
		int sum = 0;
		sum += (a + b + c + 12);
		max_val = max(max_val, sum);
	}
	cout << max_val;
}