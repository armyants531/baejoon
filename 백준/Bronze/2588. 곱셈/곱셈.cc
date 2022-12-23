#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int A;
	string B;
	cin >> A >> B;
	cout << A * (B[2] - '0') << "\n";
	cout << A * (B[1] - '0') << "\n";
	cout << A * (B[0] - '0') << "\n";
	cout << A * stoi(B) << "\n";

	return 0;
}