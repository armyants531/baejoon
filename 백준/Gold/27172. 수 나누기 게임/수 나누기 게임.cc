// 수 나누기 게임  // 정수론  // 에라토스테네스의 체
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
	vector<int> check(1000001);
	vector<int> point(1000001);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
		check[a] = 1;
	}
	for (int i = 0; i < N; i++) {
		int j = 2;
		while (arr[i] * j <= 1000000) {
			int aj = arr[i] * j;
			if (check[aj] == 1) {
				point[aj]--;
				point[arr[i]]++;
			}
			j++;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << point[arr[i]] << " ";
	}
}