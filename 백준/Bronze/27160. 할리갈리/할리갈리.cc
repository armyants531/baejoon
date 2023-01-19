#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(4);
	for (int i = 0; i < N; i++) {
		string A;
		int x;
		cin >> A;
		cin >> x;
		if (A == "STRAWBERRY") {
			arr[0] += x;
		}
		else if (A == "BANANA") {
			arr[1] += x;
		}
		else if (A == "LIME") {
			arr[2] += x;
		}
		else {
			arr[3] += x;
		}
	}
	bool have = false;
	for (auto i : arr) {
		if (i == 5) {
			have = true;
			break;
		}
	}
	if (have) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}