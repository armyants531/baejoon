#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    vector<bool> arr(N);
    vector<bool> arr2(N);
    int a;
    for (int i = 0; i < M; i++) {
        cin >> a;
        arr2[a] = true;
    }
    while (K > 0) {
        for (int i = 1; i <= N - 2; i++) {
            if (arr2[i - 1] != arr2[i + 1]) {
                arr[i] = true;
            }
        }
        if (arr2[N - 1] != arr2[1]) {
            arr[0] = true;
        }
        if (arr2[N - 2] != arr2[0]) {
            arr[N - 1] = true;
        }
        K--;
        for (int i = 0; i < N; i++) {
            arr2[i] = arr[i];
        }
        arr.clear();
        arr.resize(N);
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (arr2[i]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}