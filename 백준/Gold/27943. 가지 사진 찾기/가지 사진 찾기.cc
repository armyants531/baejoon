// 가지 사진 찾기  // 이분 탐색
// 중앙에는 가지 사진이 항상 배치됨
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll N;

// 범위의 하한 찾기
ll binarySearch1(string gaji, ll start, ll end) {
    string s;
    ll mid = (start + end) / 2;
    ll ans = (1 + N) / 2;
    while (start <= end) {
        mid = (start + end) / 2;
        cout << "? " << mid << "\n";
        cout << flush;
        cin >> s;
        if (s == gaji) {
            end = mid - 1;
            ans = min(ans, mid);
        }
        else {
            start = mid + 1;
        }
    }
    return ans;
}

// 범위의 상한 찾기
ll binarySearch2(string gaji, ll start, ll end) {
    string s;
    ll mid = (start + end) / 2;
    ll ans = (1 + N) / 2;
    while (start <= end) {
        mid = (start + end) / 2;
        cout << "? " << mid << "\n";
        cout << flush;
        cin >> s;
        if (s == gaji) {
            start = mid + 1;
            ans = max(ans, mid);
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    string s;
    ll mid = (1 + N) / 2;
    cout << "? " << mid << "\n";
    cout << flush;
    cin >> s;
    ll left = binarySearch1(s, 1, mid);
    ll right = binarySearch2(s, mid + 1, N);
    cout << "! " << left << " " << right << "\n";
    cout << flush;

    return 0;
}