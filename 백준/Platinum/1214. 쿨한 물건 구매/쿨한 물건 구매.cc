// 쿨한 물건 구매  // 정수론
// D <= i * P + j * Q
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll D, P, Q;
    cin >> D >> P >> Q;
    if (P > Q) { // P <= Q 가 되도록 순서 변경
        swap(P, Q);
    }
    ll min_cost = 2000000001;

    ll PQ = P * Q;
    ll j_max = D / Q + 1; // j의 최댓값
    j_max = min(P - 1, j_max); // j는 P 이상일 필요가 없음 Q*P == P*Q 이기 때문
    for (ll j = 0; j <= j_max; j++) {
        ll val = D - j * Q;
        if (val >= 0) {
            ll i = ceil((double) val / P); // N 이상이면서 N과 가장 가까운 i * P + j * Q 값 계산 
            //cout << "i : " << i << "  j : " << j << "\n";
            min_cost = min(min_cost, i * P + j * Q);
        }
        else { // val < 0 (i = 0)
            min_cost = min(min_cost, j * Q);
        }
        if (min_cost == D) break;
    }
    cout << min_cost << "\n";
}