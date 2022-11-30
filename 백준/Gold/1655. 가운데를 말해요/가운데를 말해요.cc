// 가운데를 말해요  // priority queue
// https://velog.io/@uuuouuo/heap 참고(아이디어)
// 최소 힙, 최대 힙을 만들고 아래의 두 규칙을 따르면 최대 힙의 top이 중간값
// 1. 최대 힙의 top은 최소 힙의 top 이하
// 2. 최대 힙의 크기는 최소 힙과 같거나 1 크다
#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int val;
    cin >> val;
    max_heap.push(val); // 처음에는 최대 힙에 저장
    cout << max_heap.top() << "\n";
    for (int i = 0; i < N - 1; i++) {
        cin >> val;
        if (max_heap.top() <= val) {
            min_heap.push(val);
            if (max_heap.size() < min_heap.size()) {
                val = min_heap.top();
                // 개수 조건 맞추기
                max_heap.push(val);
                min_heap.pop();
            }
        }
        else { // max_heap.top() > val
            max_heap.push(val);
            if (max_heap.size() > min_heap.size() + 1) {
                val = max_heap.top();
                // 개수 조건 맞추기
                min_heap.push(val);
                max_heap.pop();
            }
        }
        cout << max_heap.top() << "\n";
    }

    return 0;
}