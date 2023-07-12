// binary는 호남선
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N; 
	cout << "? " << 1 << "\n"; 
	cout << flush;
	int first;
	cin >> first;
	cout << "? " << N << "\n"; 
	cout << flush;
	int last;
	cin >> last;
	if (first == last) {
		cout << "! " << 0 << "\n";
	}
	else if (first < last) {
		cout << "! " << 1 << "\n"; 
	}
	else {
		cout << "! " << -1 << "\n";
	}
}