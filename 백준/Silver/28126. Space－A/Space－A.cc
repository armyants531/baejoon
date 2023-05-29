// Space-A  // math
// R, U, X의 개수를 세서 도달 가능한지 여부 판단
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int R = 0;
    int U = 0;
    int X = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') {
            R++;
        }
        else if (s[i] == 'U') {
            U++;
        }
        else {
            X++;
        }
    }
    int K;
    cin >> K;
    int cnt = 0; // 탐사 가능 지점의 수
    int x, y;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        x--;
        y--;
        if (x - y <= R && y - x <= U && R + X >= x && U + X >= y) {
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}