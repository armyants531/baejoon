// 트럭  // queue
// 다리를 길이가 w인 큐로 생각하고, 다리의 최대하중(L)을 초과해 트럭이 다리를 지날 수 없으면 무게가 0인 가상의 트럭을 push
// 큐에 트럭이 꽉 차면 pop, 트럭이 큐에 들어갈 때마다 시간 1 증가
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, w, L;
    int cnt = 0;
    int weight_sum = 0;
    cin >> n >> w >> L;
    queue<int> bridge;
    queue<int> tracks;

    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        tracks.push(val);
    }
    while (!tracks.empty()) {
        val = tracks.front();
        if (bridge.size() == w) { // 다리에 트럭이 꽉 차있을 때
            int front_a = bridge.front();
            bridge.pop(); // 맨 앞 차 나감
            weight_sum -= front_a;
        }
        if (weight_sum + val > L) { // 다음 트럭이 바로 다리에 진입할 수 없을 때(최대하중 초과)
            while (bridge.size() < w) { // 다리 위 트럭의 수와 w가 같아질 때 까지
                bridge.push(0);
                cnt++;
            }
        } 
        if (weight_sum + val <= L && bridge.size() < w) { // 다음 트럭이 바로 다리에 진입 가능할 때
            bridge.push(val); // 트럭 삽입
            cnt++;
            weight_sum += val;
            tracks.pop();
        }
        /*
        // test
        queue<int> bridge2 = bridge;
        for (int i = 0; i < bridge.size(); i++) {
            cout << bridge2.front() << " ";
            bridge2.pop();
        }
        cout << "\n";
        */
    }
    cnt += w; // 마지막 트럭이 들어온 이후, 나가는데 걸리는 시간 더함
    cout << cnt << "\n";

    return 0; 
}