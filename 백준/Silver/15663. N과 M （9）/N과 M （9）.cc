// N과 M (9)  // backtracking  // dfs
// https://m.blog.naver.com/js568/221857286945 참고
#include <algorithm> // sort
#include <iostream>
#include <vector>

using namespace std;

vector<int> series(8);
vector<int> arr;
vector<bool> visited(8);
int N, M;


void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << series[i] << " ";
        }
        cout << "\n";
        return;
    }
    else {
        int last_ele = 0; // 이전 수열의 마지막 원소
        for (int i = 0; i < N; i++) {
            if (!visited[i] && arr[i] != last_ele) { // 이전 수열의 마지막 원소와 현재 원소가 다르면 dfs 진행
                visited[i] = true;
                last_ele = arr[i];
                series[cnt] = arr[i];
                dfs(cnt + 1);
                visited[i] = false;
            }
        }
    }
}

int main() {
    // init visited
    for (int i = 0; i < 8; i++) {
        visited.push_back(false);
    }
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());

    dfs(0);

    return 0;
}