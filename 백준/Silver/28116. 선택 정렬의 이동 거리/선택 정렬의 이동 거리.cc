#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> arr(N + 1);
	map<int, int> mp; // 각 수의 idx 저장
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		mp[A[i]] = i;
	}
	for (int i = 1; i <= N; i++) {
		int idx = mp[i];
		arr[A[i - 1]] += idx - (i - 1);
		arr[A[idx]] += idx - (i - 1);
		
		int temp = A[i - 1];
		mp[temp] = idx;
		A[i - 1] = A[idx];
		A[idx] = temp;
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}
}