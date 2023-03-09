// 친구 네트워크  // disjoint set  // Union-Find Alg
#include <bits/stdc++.h>

using namespace std;

map<string, int> cnt;
map<string, string> parent;

string get_parent(string x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = get_parent(parent[x]);
}

void union_parent(string x, string y) {
    x = get_parent(x);
    y = get_parent(y);
    if (x < y) {
        parent[y] = x; // x가 y의 부모
        cnt[x] += cnt[y];
    }
    else {
        parent[x] = y;
        cnt[y] += cnt[x];
    }
}

bool same_parent(string x, string y) {
    return get_parent(x) == get_parent(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cnt.clear();
        parent.clear();
        int F;
        cin >> F;
        for (int f = 0; f < F; f++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (!cnt.count(s1)) { // 처음 입력되었으면
                parent[s1] = s1;
                cnt[s1] = 1;
            }
            if (!cnt.count(s2)) {
                parent[s2] = s2;
                cnt[s2] = 1;
            }
            if (!same_parent(s1, s2)) { // 부모가 다르면
                union_parent(s1, s2);
            }
         
            cout << cnt[get_parent(s1)] << "\n";
        }
    }
}