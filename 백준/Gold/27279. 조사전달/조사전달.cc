#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M; 
	cin >> N >> M;
	vector<int> arr(M, 0);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr[a - 1]++;
	}
	vector<int> B;
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		B.push_back(b);
	}
	sort(B.begin(), B.end());
	bool possi = true;
	for (int i = M - 1; i >= 0; i--) {
		if (B[i] <= arr[i]) {
			if (i >= 1) {
				arr[i - 1] += (arr[i] - B[i]);
			}
		}
		else {
			possi = false;
			break;
		}
	}
	if (!possi) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
}