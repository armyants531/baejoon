// 디지털 XOR  // greedy
// xor해서 0이 되는 수 조합: {5, 6, 8, 9}, {1, 2, 3, 5, 8}, {1, 2, 3, 6, 9}
// 합이 같은 것 중 곱이 작게 하려면 두 수의 자릿수를 비교했을 때 항상 한쪽이 더 크거나 같아야 함
// 4와 7이 주어진 수에 있는 경우: 수 3개의 합으로 표현
// 4, 7이 없는 경우: 수 3개 vs 수 4개의 합 비교(같은 경우는 없음)
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int N = s.size();
	bool has47 = false;
	for (int i = 0; i < N; i++) {
		if (s[i] == '4' || s[i] == '7') {
			has47 = true;
		}
	}
	if (has47) { // 4 또는 7이 있으면 4개 수의 합으로는 못 나타냄
		string A, B, C;
		for (int i = 0; i < N; i++) {
			if (s[i] == '1') {
				A += '1';
				B += '1';
				C += '1';
			}
			else if (s[i] == '2') {
				A += '2';
				B += '2';
				C += '2';
			}
			else if (s[i] == '3') {
				A += '3';
				B += '3';
				C += '3';
			}
			else if (s[i] == '4') {
				A += '4';
				B += '4';
				C += '4';
			}
			else if (s[i] == '5') {
				A += '5';
				B += '5';
				C += '5';
			}
			else if (s[i] == '6') {
				A += '6';
				B += '6';
				C += '6';
			}
			else if (s[i] == '7') {
				A += '7';
				B += '7';
				C += '7';
			}
			else if (s[i] == '8') {
				A += '5';
				B += '6';
				C += '9';
			}
			else { // 9
				A += '5';
				B += '6';
				C += '8';
			}
		}
		vector<int> result(N + 1);
		int carry = 0;
		int sum;
		for (int i = N - 1; i >= 0; i--) {
			sum = (A[i] - '0') + (B[i] - '0') + (C[i] - '0') + carry;
			carry = sum / 10;
			sum %= 10;
			result[i + 1] = sum;
		}
		if (carry) {
			result[0] = carry;
			cout << result[0];
		}
		for (int i = 1; i <= N; i++) {
			cout << result[i];
		}
		cout << " " << 3 << "\n";
		cout << A << "\n" << B << "\n" << C << "\n";
	}
	else {
		string A, B, C;
		for (int i = 0; i < N; i++) {
			if (s[i] == '1') {
				A += '1';
				B += '1';
				C += '1';
			}
			else if (s[i] == '2') {
				A += '2';
				B += '2';
				C += '2';
			}
			else if (s[i] == '3') {
				A += '3';
				B += '3';
				C += '3';
			}
			else if (s[i] == '4') {
				A += '4';
				B += '4';
				C += '4';
			}
			else if (s[i] == '5') {
				A += '5';
				B += '5';
				C += '5';
			}
			else if (s[i] == '6') {
				A += '6';
				B += '6';
				C += '6';
			}
			else if (s[i] == '7') {
				A += '7';
				B += '7';
				C += '7';
			}
			else if (s[i] == '8') {
				A += '5';
				B += '6';
				C += '9';
			}
			else { // 9
				A += '5';
				B += '6';
				C += '8';
			}
		}
		vector<int> result1(N + 1);
		int carry = 0;
		int sum;
		for (int i = N - 1; i >= 0; i--) {
			sum = (A[i] - '0') + (B[i] - '0') + (C[i] - '0') + carry;
			carry = sum / 10;
			sum %= 10;
			result1[i + 1] = sum;
		}
		if (carry) {
			result1[0] = carry;
		}

		string D, E, F, G;
		for (int i = 0; i < N; i++) {
			if (s[i] == '1') {
				D += '2';
				E += '3';
				F += '5';
				G += '8';
			}
			else if (s[i] == '2') {
				D += '1';
				E += '3';
				F += '5';
				G += '8';
			}
			else if (s[i] == '3') {
				D += '1';
				E += '2';
				F += '5';
				G += '8';
			}
			else if (s[i] == '5') {
				D += '1';
				E += '2';
				F += '3';
				G += '8';
			}
			else if (s[i] == '6') {
				D += '1';
				E += '2';
				F += '3';
				G += '9';
			}
			else if (s[i] == '8') {
				D += '1';
				E += '2';
				F += '3';
				G += '5';
			}
			else { // 9
				D += '1';
				E += '2';
				F += '3';
				G += '6';
			}
		}
		vector<int> result2(N + 1);
		carry = 0;
		sum = 0;
		for (int i = N - 1; i >= 0; i--) {
			sum = (D[i] - '0') + (E[i] - '0') + (F[i] - '0') + (G[i] - '0') + carry;
			carry = sum / 10;
			sum %= 10;
			result2[i + 1] = sum;
		}
		if (carry) {
			result2[0] = carry;
		}
		int num;
		for (int i = 0; i <= N; i++) {
			if (result1[i] > result2[i]) {
				num = 2;
				break;
			}
			else if (result1[i] < result2[i]) {
				num = 1;
				break;
			}
		}
		if (num == 1) {
			if (result1[0]) cout << result1[0];
			for (int i = 1; i <= N; i++) {
				cout << result1[i];
			}
			cout << " " << 3 << "\n";
			cout << A << "\n" << B << "\n" << C << "\n";
		}
		else {
			if (result2[0]) cout << result2[0];
			for (int i = 1; i <= N; i++) {
				cout << result2[i];
			}
			cout << " " << 4 << "\n";
			cout << D << "\n" << E << "\n" << F << "\n" << G << "\n";
		}
	}

	return 0;
}