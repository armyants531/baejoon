#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	double score;
	double MAX = 0;
	double tot = 0;
	for (int i = 0; i < N; i++) {
		cin >> score;
		tot += score;
		MAX = max(MAX, score);
	}
	cout << fixed;
	cout.precision(6);
	cout << (tot / N) * (100 / MAX) << "\n";

	return 0;
}