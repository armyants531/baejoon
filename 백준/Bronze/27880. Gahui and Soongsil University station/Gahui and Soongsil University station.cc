#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	int h;
	int d = 0;
	for (int i = 0; i < 4; i++) {
		cin >> s >> h;
		if (s == "Es") {
			d += 21 * h;
		}
		else {
			d += 17 * h;
		}
	}
	cout << d << "\n";

	return 0;
}