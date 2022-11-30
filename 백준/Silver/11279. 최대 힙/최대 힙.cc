// 최대 힙  // priority queue
#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>> max_heap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int val;
    for (int i = 0; i < N; i++) {
        cin >> val;
        if (val == 0) {
            if (max_heap.empty()) {
                cout << 0 << "\n";
            }
            else {
                int t = max_heap.top();
                cout << t << "\n";
                max_heap.pop();
            }
        }
        else {
            max_heap.push(val);
        }
    }
    return 0;
}