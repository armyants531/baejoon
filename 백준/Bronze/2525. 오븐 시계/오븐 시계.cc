#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int A, B;
	cin >> A >> B;
	int C;
	cin >> C;
	int dh = C / 60;
	int dm = C % 60;
	dh += (B + dm) / 60;
	int m = (B + dm) % 60;
	int h = (A + dh) % 24;
	cout << h << " " << m << "\n";

	return 0;
}