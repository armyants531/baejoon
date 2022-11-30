// 절댓값 힙  // priority queue
#include <bits/stdc++.h>

using namespace std;

struct compare {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        else {
            return abs(a) > abs(b);
        }
    }
};

priority_queue<int, vector<int>,compare> abs_heap;

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
            if (abs_heap.empty()) {
                cout << 0 << "\n";
            }
            else {
                int t = abs_heap.top();
                cout << t << "\n";
                abs_heap.pop();
            }
        }
        else {
            abs_heap.push(val);
        }
    }
    return 0;
}