// 막대기  // bitmasking 
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int X;
	cin >> X;
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		if (X & (1 << i)) {
			cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;
}