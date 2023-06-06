#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, M;
    cin >> N >> M;
    vector<queue<int>> order(200001);
    int k, a;
    for (int i = 1; i <= N; i++) {
    	cin >> k;
    	for (int j = 0; j < k; j++) {
    		cin >> a;
    		order[a].push(i);
		}
	}
	vector<int> cnt(N + 1);
	int b;
	for (int i = 0; i < M; i++) {
		cin >> b;
		if (!order[b].empty()) {
			int t = order[b].front();
			order[b].pop();
			cnt[t]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << cnt[i] << " ";
	}
	cout << "\n";
}