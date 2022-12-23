#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<vector<int>> arr(3);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr[0].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr[1].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr[2].push_back(a);
	}
	int pre = -1;
	bool posi = true;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		a = arr[0][i];
		b = arr[1][i];
		c = arr[2][i];
		vector<int> temp = { a, b, c };
		sort(temp.begin(), temp.end());
		if (temp[1] <= pre) {
			temp[1] = pre + 1;
		}
		else {
			temp[2] = pre + 1;
		}
		sort(temp.begin(), temp.end());
		//cout << temp[0] << " " << temp[1] << " " << temp[2] << "\n";
		if (temp[1] > pre) {
			pre = temp[1];
		}
		else {
			posi = false;
			break;
		}
	}
	if (posi) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
	
	return 0;
}