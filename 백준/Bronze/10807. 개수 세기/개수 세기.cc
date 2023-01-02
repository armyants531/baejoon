#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(201);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr[num + 100]++;
	}
	int v;
	cin >> v;
	cout << arr[v + 100] << "\n";
	
	return 0;
}