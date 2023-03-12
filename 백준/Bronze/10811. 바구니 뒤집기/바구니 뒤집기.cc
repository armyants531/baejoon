#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		for (int j = a; j <= (a + b) / 2; j++) {
			int temp = arr[j];
			arr[j] = arr[a + b - j];
			arr[a + b - j] = temp;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	
	return 0;
}