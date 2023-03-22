// 알고리즘 수업 - 점근적 표기 1
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a1, a0;
	cin >> a1 >> a0;
	int c;
	cin >> c;
	int n0;
	cin >> n0;
	if (a1 * n0 + a0 <= c * n0 && a1 <= c) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
}