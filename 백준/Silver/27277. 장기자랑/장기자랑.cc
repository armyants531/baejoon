#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	ll sum = 0;
	if (N % 2 == 0) {
		sum += arr[N - 1];
		for (int i = 0; i < N / 2 - 1; i++) {
			sum += arr[N - 2 - i] - arr[i];
		}
	}
	else {
		sum += arr[N - 1];
		for (int i = 0; i < N / 2; i++) {
			sum += arr[N - 2 - i] - arr[i];
		}
	}
	cout << sum;
}