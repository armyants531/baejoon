// Gravity Hackenbush  // game theory
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
	}
	int R = 0;
	int G = 0;
	int B = 0;
	for (int i = 0; i < M; i++) {
		int x, y;
		char color;
		cin >> x >> y >> color;
		if (color == 'R') {
			R++;
		}
		else if (color == 'B') {
			B++;
		}
		else {
			G++;
		}
	}
	if (R > B) {
		cout << "jhnah917" << "\n";
	}
	else if (R < B) {
		cout << "jhnan917" << "\n";
	}
	else { // R == B
		if (G % 2 == 0) {
			cout << "jhnan917" << "\n";
		}
		else {
			cout << "jhnah917" << "\n";
		}
	}
	return 0;
}