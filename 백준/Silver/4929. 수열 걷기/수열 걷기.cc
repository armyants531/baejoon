#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while (n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        a.push_back(10001);
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        b.push_back(10001);
        int sa = 0, sb = 0, sum = 0; // 수열1, 2의 구간합 / 최대합
        int i = 0, j = 0;
        while (i < a.size() || j < b.size()) {  
            if (a[i] == b[j]) {
                sa+=a[i];
                sb+=b[j];
                sum += max(sa, sb);
                sa = 0;
                sb = 0;
                i++;
                j++;
            }
            else if (a[i] > b[j]) {
                sb+=b[j];
                j++;
            }
            else {
                sa+=a[i];
                i++;
            }
        }
        sum -= 10001;
        cout << sum << "\n";
        cin >> n;
    }

    return 0;
}