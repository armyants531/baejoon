// 지연 평가  // ad-Hoc
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Q;
    cin >> Q;
    int order, x;
    ll min_val = 1; // 가장 작은 정수
    ll step = 1; // 각 수 사이의 간격 
    for (int i = 0; i < Q; i++) {
        cin >> order;
        if (order == 0) {
            cin >> x;
            min_val += x;
        }
        else if (order == 1) {
            cin >> x;
            step *= x;
            min_val *= x;
        }
        else if (order == 2) {
            cin >> x;
            min_val += step * x;
        }
        else {
            cout << min_val << "\n";
        }
    }

    return 0;
}