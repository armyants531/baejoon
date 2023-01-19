#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; 
	cin >> N;
	int time = 12;
	bool back = false;
	for (int i = 1; i <= N; i++) {
		string s;
		int x;
		cin >> s >> x;
		if (back) {
			if (time == 1) {
				time = 12;
			}
			else {
				time--;
			}
		}
		else {
			if (time == 12) {
				time = 1;
			}
			else {
				time++;
			}
		}
		if (s == "HOURGLASS") {
			if (time == x) {
				cout << time << " " << "NO" << "\n";
			}
			else {
				back = !back;
				cout << time << " " << "NO" << "\n";
			}
		}
		else {
			if (time == x) {
				cout << time << " " << "YES" << "\n";
			}
			else {
				cout << time << " " << "NO" << "\n";
			}
		}
	}
}