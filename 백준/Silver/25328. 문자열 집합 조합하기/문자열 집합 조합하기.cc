// 문자열 집합 조합하기 
// 문자열 내 중복된 문자 x -> 부분문자열 중 중복 x
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

map<string, int> mp;
string x, y, z;
int k;

void dfs(int idx, string s, string init) {
    if (idx == init.size()) {
        if (s != "") {
            mp[s]++;
        }
        return;
    }
    dfs(idx + 1, s, init);
    dfs(idx + 1, s + init[idx], init);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> x >> y >> z;
    cin >> k;
    dfs(0, "", x);
    dfs(0, "", y);
    dfs(0, "", z);
    bool none = true;
    for (auto st : mp) {
        //cout << st.fi << " " << st.se << "\n";
        if (st.se > 1 && st.fi.size() == k) {
            cout << st.fi << "\n";
            none = false;
        }
    }
    if (none) cout << -1 << "\n";

    return 0;
}