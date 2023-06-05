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
    reverse(a.begin(), a.end());
    vector<ll> cnt(M); // 각 상품을 몇 개씩 사야하는지 기록 
    // 가장 싼 것을 N개 사기 
    ll cheapest = a[0];
    X -= cheapest * N;
    for (int i = 0; i < M; i++) {
        a[i] -= cheapest;
    }
    cnt[0] = N;
    ll remain = N; // 남은 사람 수 
    while (X) {
        int idx = upper_bound(a.begin(), a.end(), X) - a.begin(); // X보다 큰 값의 인덱스
        if (idx == 1) {
            break;
        }
        ll q = X / a[idx - 1];  // 줄 수 있는 사람 수 
        if (q >= remain) { // 남은 사람 수 이상이면 
            cnt[idx - 1] += remain;
            cnt[0] -= remain;
            break;
        }
        cnt[idx - 1] += q;
        cnt[0] -= q;
        X %= a[idx - 1];
        remain -= q; // 남은 사람 수 갱신 
    }
    for (int i = M - 1; i >= 0; i--) {
        cout << cnt[i] << " ";
    }
    cout << "\n";

    return 0;
}