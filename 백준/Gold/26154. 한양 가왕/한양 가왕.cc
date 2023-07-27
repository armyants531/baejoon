#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<priority_queue<int, vector<int>>> arr(N);
	for (int i = 0; i < N; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		arr[i].push(p1);
		arr[i].push(p2);
	}
	if (N - 1 >= M) {
		for (int i = 0; i < M; i++) {
			vector<int> p(N);
			for (int j = 1; j < N; j++) {
				p[j - 1] = arr[j].top();
				arr[j].pop();
			}
			int f = arr[0].top();
			arr[0].pop();
			p[N - 1] = arr[0].top();
			arr[0].pop();
			arr[0].push(f);
			for (int j = 0; j < N; j++) {
				arr[j].push(p[j]);
			}
		}
	}
	else {
		int rem = (M - (N - 1)) % N;
		for (int i = 0; i < N - 1 + rem; i++) {
			vector<int> p(N);
			for (int j = 1; j < N; j++) {
				p[j - 1] = arr[j].top();
				arr[j].pop();
			}
			int f = arr[0].top();
			arr[0].pop();
			p[N - 1] = arr[0].top();
			arr[0].pop();
			arr[0].push(f);
			for (int j = 0; j < N; j++) {
				arr[j].push(p[j]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int b = arr[i].top();
		arr[i].pop();
		int a = arr[i].top();
		cout << a << " ";
		cout << b << "\n";
	}
	
	return 0;
}