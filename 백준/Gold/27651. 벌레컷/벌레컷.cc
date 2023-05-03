// 벌레컷  // prefix sum  // binary search
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector<ll> preSum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int A;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A;
        sum += A;
        preSum.push_back(sum);
    }
    // preSum[X] < sum - preSum[Y] < preSum[Y] - preSum[X]
    // (sum + preSum[X]) / 2 < preSum[Y] < sum - preSum[X]
    ll cnt = 0;
    for (int x = 0; x < N; x++) {
        //cout << x << " : ";
        int low = upper_bound(preSum.begin(), preSum.end(), (sum + preSum[x]) / 2) - preSum.begin();
        int high = lower_bound(preSum.begin(), preSum.end(), sum - preSum[x]) - preSum.begin();
        int diff = high - low;
        if (diff > 0) cnt += diff;
        //cout << low << " " << high << "\n";
    }
    cout << cnt << "\n";

    return 0;
}