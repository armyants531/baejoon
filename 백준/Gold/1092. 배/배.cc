// 배  // greedy
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> crane(N);
    for (int i = 0; i < N; i++) {
        cin >> crane[i];
    }
    int M;
    cin >> M;
    vector<int> box(M);
    for (int i = 0; i < M; i++) {
        cin >> box[i];
    }
    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());
    int T = 0;
    if (crane[N - 1] < box[M - 1]) {
        cout << -1 << "\n";
    }
    else {
        bool isEmpty = false;
        while (!box.empty()) {
            for (int i = N - 1; i >= 0; i--) {
                for (int j = box.size() - 1; j >= 0; j--) {
                    if (box.empty()) {
                        isEmpty = true;
                        break;
                    }
                    if (crane[i] >= box[j]) {
                        box.erase(box.begin() + j);
                        break;
                    }
                }
                if (isEmpty) {
                    break;
                }
            }
            T++;
        }
        cout << T << "\n";
    }
    
    return 0;
}