#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	cin >> N;
	int day;
	cin >> day;
	int tot_day = 365; // 나머지 1
	if ((N % 4 == 0 && N % 100 != 0) || (N % 400 == 0)) {
		tot_day++;
	}
	if (tot_day == 365)
		cout << 29 << "\n";
	else {
		cout << 30 << "\n";
	}

	return 0;
}