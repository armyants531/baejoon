#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, M, X;
    cin >> N >> M >> X;
    vector<ll> a(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i];
    }
    vector<ll> cnt(M); // 각 상품을 몇 개씩 사야하는지 기록 
    ll remain = N;
	for (int i = 0; i < M - 1; i++) {
    	cnt[i] = min((ll)floor((double)(X - a[M - 1] * remain) / (a[i] - a[M - 1])), remain);
		if (cnt[i] <= 0) continue;
		remain -= cnt[i];
    	X -= a[i] * cnt[i];
    	if (remain == 0) break;
	}
	cnt[M - 1] = remain;
	for (int i = 0; i < M; i++) {
        cout << cnt[i] << " ";
    }
    cout << "\n";
}