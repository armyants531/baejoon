#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    long long sum = 0;
    int le = 0, ri = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            le++;
            ri = 0;
        }
        else {
            ri++;
            le--;
            if (ri == 1) {
                sum += le;
            }
        }
    }
    cout << sum << "\n";
}