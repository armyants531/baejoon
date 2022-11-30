// 좋은 친구  // queue  // Sliding Window
// 이름의 길이가 2~20에 해당하는 큐(큐에는 사람의 인덱스를 저장)를 만들고 이름을 입력 받을 때마다
// 이름의 길이에 해당하는 큐의 front의 인덱스와 인덱스 차이가 K이하이면
// 해당 큐의 크기 만큼 pair의 개수를 증가, 인덱스 차이가 K보다 크면 K이하가 될 때까지 pop
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    ll cnt = 0;
    cin >> N >> K;
    queue<int> que[19];
    string name; 
    int len;
    for (int i = 0; i < N; i++) {
        cin >> name;
        len = name.length() - 2; // 이름 길이 2 감소(이름은 길이가 2이상임)
        // 큐의 front와 인덱스 차이가 K보다 크면 K이하가 될 때까지 pop
        while (!que[len].empty() && i - que[len].front() > K) {
            que[len].pop();
        }
        cnt += que[len].size(); // 친구 수 count
        que[len].push(i); // 길이에 해당하는 큐에 인덱스 push
    }
    cout << cnt << "\n";

    return 0;
}