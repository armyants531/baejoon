#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int main(void) {
	int nA, nB, M;
	int cnt = 0;
	bool check = false;  // check if there is an odd-odd pair
	cin >> nA >> nB;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		if ((A % 2 == 1) && (B % 2 == 1)) {
			check = true;
		}
	}
	if (check && (nA % 2 == 1) && (nB % 2 == 1)) {
		cout << nA / 2 + nB / 2 + 1 << "\n";
	}
	else {
		cout << nA / 2 + nB / 2 << "\n";
	}
}