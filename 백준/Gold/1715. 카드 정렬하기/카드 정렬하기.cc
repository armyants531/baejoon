// 카드 정렬하기  // greedy  // priority queue 
// 계속해서 가장 작은 두 카드 묶음을 합쳐주면 최소 비교 횟수를 얻을 수 있다.
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
// 최소 힙
priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int val;
    for (int i = 0; i < N; i++) {
        cin >> val;
        min_heap.push(val);
    }
    ll cnt = 0;
    while (min_heap.size() > 1) {
        int A = min_heap.top();
        min_heap.pop();
        int B = min_heap.top();
        min_heap.pop();
        cnt += A + B;
        // A + B를 최소 힙에 삽입
        min_heap.push(A + B);
    }
    cout << cnt << "\n";

    return 0;
}