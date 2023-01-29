#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string A, B;
	cin >> A >> B;
	if (A.size() > B.size()) {
		int diff = A.size() - B.size();
		for (int i = 0; i < diff; i++) {
			B = '0' + B;
		}
	}
	else {
		int diff = B.size() - A.size();
		for (int i = 0; i < diff; i++) {
			A = '0' + A;
		}
	}
	//cout << A << " " << B << "\n";
	int N = max(A.size(), B.size());
	vector<char> result(N + 1);
	int carry = 0;
	int sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		sum = (A[i] - '0') + (B[i] - '0') + carry;
		carry = sum / 10;
		sum %= 10;
		result[i + 1] = sum + '0';
	}
	if (carry != 0) {
		result[0] = carry + '0';
		cout << result[0] << "";
	}
	for (int i = 1; i <= N; i++) {
		cout << result[i] << "";
	}
}