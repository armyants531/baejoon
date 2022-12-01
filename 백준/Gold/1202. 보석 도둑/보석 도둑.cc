// 보석 도둑  // greedy  // priority queue  // sort
// 보석과 가방을 무게를 기준으로 오름차순 정렬한 후,
// 가방에 들어갈 수 있는 보석들을 가격 기준으로 max_heap에 삽입
// max_heap에서 pop하고 다음 가방으로 넘어감
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct compare {
    // 가격에 대해 내림차순 정렬
    bool operator()(pair<ll, ll> const& a, pair<ll, ll> const& b) {
        return a.second < b.second;
    }
};

// save gems info <M, V>
vector<pair<ll, ll>> gems;
queue<pair<ll, ll>> gems_que; 
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, compare> max_heap;

// save the max weight of bags
vector<ll> bags;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll M, V;
        cin >> M >> V; // weight, price
        gems.push_back({ M, V });
    }
    ll c;
    for (int i = 0; i < K; i++) {
        cin >> c;
        bags.push_back(c);
    }
    // 보석 정렬(무게에 대해 오름차순)
    sort(gems.begin(), gems.end());
    // 가방 정렬(무게에 대해 오름차순)
    sort(bags.begin(), bags.end());

    for (int i = 0; i < gems.size(); i++) {
        gems_que.push(gems[i]);
    }

    ll sum = 0;
    for (int i = 0; i < bags.size(); i++) {
        while (!gems_que.empty()) {
            if (bags[i] >= gems_que.front().first) { // 가방에 보석이 들어갈 수 있으면
                max_heap.push(gems_que.front());
                gems_que.pop();
            }
            else {
                break;
            }
        }
        if (!max_heap.empty()) {
            sum += max_heap.top().second; // 가격의 합 갱신(가방에 넣음)
            max_heap.pop();
        }
    }
    cout << sum << "\n";
    return 0;
}