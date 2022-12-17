// 집합  // bitmasking
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M;
	cin >> M;
	int S = 0;
	for (int i = 0; i < M; i++) {
		string order;
		int x;
		cin >> order;
		if (order == "add") {
			cin >> x;
			S = S | (1 << x); // x번 비트를 1로 바꾸어 줌
		}
		else if (order == "remove") {
			cin >> x;
			S = S & ~(1 << x); // x번 비트를 0으로 바꾸어 줌
		}
		else if (order == "check") {
			cin >> x;
			if (S & (1 << x)) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (order == "toggle") {
			cin >> x;
			S = S ^ (1 << x);
		}
		else if (order == "all") {
			S = (1 << 21) - 1;
		}
		else { // empty
			S = 0;
		}
	}

	return 0;
}