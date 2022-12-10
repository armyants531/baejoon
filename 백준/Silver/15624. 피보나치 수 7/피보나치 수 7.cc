#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<ll, ll> mp;

ll fibonacci(ll n) {
    if (n == 0 || mp[n] != 0) {
        return mp[n];
    }
    if (n % 2 == 0) {
        ll m = n / 2;
        mp[n] = (2 * fibonacci(m) * fibonacci(m - 1) +
            fibonacci(m) * fibonacci(m)) %
            1000000007;
        return mp[n];
    }
    else {
        ll m = (n - 1) / 2;
        mp[n] = (fibonacci(m + 1) * fibonacci(m + 1) +
            fibonacci(m) * fibonacci(m)) %
            1000000007;
        return mp[n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    mp[0] = 0;
    mp[1] = 1;
    cout << fibonacci(n) << "\n";

    return 0;
}