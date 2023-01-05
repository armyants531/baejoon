#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;
	int d = 2;
	if (x == 0) {
		cout << "GBSISTHEBEST" << "\n";
	}
	else if (x == 1) {
		cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZ" << "\n";
	}
	else {
		int remain = x;
		while (remain) {
			int a = sqrt(remain);
			remain -= a * a;
			for (int i = 0; i < a; i++) {
				cout << 'A' << "";
			}
			cout << "BCDEFGHIJKLMNOPQRSTUVWXY" << "";
			for (int i = 0; i < a; i++) {
				cout << 'Z' << "";
			}
		}
		

		/*
		
		while (remain >= 2) {
			int two = 2;
			int cnt = 1;
			while (two <= remain) {
				two *= 2;
				cnt++;
			}
			two /= 2;
			cnt--;
			if (cnt % 2 == 0) {
				for (int i = 0; i < pow(2, cnt / 2); i++) {
					cout << 'A' << "";
				}
				cout << "BCDEFGHIJKLMNOPQRSTUVWXY" << "";
				for (int i = 0; i < pow(2, cnt / 2); i++) {
					cout << 'Z' << "";
				}
			}
			else {
				for (int i = 0; i < pow(2, cnt / 2 + 1); i++) {
					cout << 'A' << "";
				}
				cout << "BCDEFGHIJKLMNOPQRSTUVWXY" << "";
				for (int i = 0; i < pow(2, cnt / 2); i++) {
					cout << 'Z' << "";
				}
			}
			remain = remain - two;
		}
		if (remain == 1) {
			cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZ" << "\n";
		}
		*/


		/*
		queue<int> p;
		while (true) {
			if (x == 1) {
				break;
			}
			else if (x % d == 0) {
				x /= d;
				p.push(d);
			}
			else {
				d++;
			}
		}
		int A = 1;
		int Z = 1;
		while (!p.empty()) {
			A *= p.front();
			p.pop();
			if (!p.empty()) {
				Z *= p.front();
				p.pop();
			}
		}

		for (int i = 0; i < A; i++) {
			cout << 'A' << "";
		}
		cout << "BCDEFGHIJKLMNOPQRSTUVWXY" << "";
		for (int i = 0; i < Z; i++) {
			cout << 'Z' << "";
		}
		*/
	}
}