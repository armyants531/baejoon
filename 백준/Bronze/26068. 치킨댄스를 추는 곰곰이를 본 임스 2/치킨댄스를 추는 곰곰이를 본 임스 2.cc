#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, cnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin.ignore();
        cin.ignore();
        int val;
        cin >> val;
        if (abs(val) <= 90) {
            cnt++;
        }
    }
    cout << cnt << "\n";
}