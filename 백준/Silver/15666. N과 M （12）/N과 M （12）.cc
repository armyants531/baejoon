// N과 M (12)  // backtracking  // dfs
#include <algorithm> // sort
#include <iostream>
#include <vector>

using namespace std;

vector<int> series(8);
vector<int> arr;
int N, M;

void dfs(int cnt, int start_idx) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << series[i] << " ";
        }
        cout << "\n";
        return;
    }
    else {
        int last_ele = 0;
        for (int i = start_idx; i < N; i++) {
            if (arr[i] != last_ele) {
                series[cnt] = arr[i];
                last_ele = arr[i];
                dfs(cnt + 1, i);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());

    dfs(0, 0);

    return 0;
}