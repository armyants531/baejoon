#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int dist = N + M + 1;
	int r, c;
	int a;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		if (dist > a) {
			r = i;
			dist = a;
		}
	}
	dist = a;
	c = 1;
	int b;
	for (int i = 2; i <= M; i++) {
		cin >> b;
		if (dist > b) {
			c = i;
			dist = b;
		}
	}
	cout << r << " " << c << "\n";
}