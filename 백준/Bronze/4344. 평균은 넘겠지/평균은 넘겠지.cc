#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int C;
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		double sum = 0;
		vector<double> point(N);
		for (int i = 0; i < N; i++) {
			cin >> point[i];
			sum += point[i];
		}
		double avg = sum / N;
		double cnt = 0;
		for (int i = 0; i < N; i++) {
			if (point[i] > avg) {
				cnt++;
			}
		}
		cout << fixed;
		cout.precision(3);
		cout << round(cnt / N * 100000) / 1000 << '%' << "\n";
	}
	
	return 0;
}