// Strongly Connected Component  // Tarjan's Algorithm
// https://blog.naver.com/ndb796/221236952158 참고
#include <bits/stdc++.h>

using namespace std;

int id = 1; // 노드별 고유 id
int scc_cnt = 0; // SCC 갯수
vector<int> parent_arr(10001, 0); // 처음 설정된 id 저장하는 리스트(부모 저장), 처음에는 0으로 초기화
bool finished[10001] = {false, };
vector<vector<int>> SCC; // SCC 저장
vector<int> adj[10001]; // adjacent list 
stack<int> st;

// dfs는 정점의 개수 만큼 실행됨
int dfs(int p) { // p: 현재 노드
    parent_arr[p] = id; // 노드마다 고유한 번호 할당 
    id++;
    st.push(p); // 스택에 자기 자신을 삽입 

    int parent = parent_arr[p]; // 부모를 고유 번호로 설정
    for (int i = 0; i < adj[p].size(); i++) { // p와 인접한 노드 탐색
        int q = adj[p][i]; // p와 인접하는 노드 중 하나
        if (parent_arr[q] == 0) { // 방문하지 않았으면
            // dfs 진행하고, 부모를 SCC내 가장 작은 값으로 갱신
            parent = min(parent, dfs(q));
        }
        else if (finished[q] == false) { // 방문은 했으나 dfs를 수행 중인 노드인 경우
            parent = min(parent, parent_arr[q]); // parent 값을 처리 중인 노드의 parent와 비교(처리 중인 이웃이 자신의 부모라면 SCC에 포함하기 위해)
        }
    }

    if (parent == parent_arr[p]) { // 부모 노드가 자기 자신인 경우
        vector<int> scc;
        while (true) {
            int t = st.top();
            finished[t] = true; // t를 종료 처리
            st.pop();
            scc.push_back(t);
            if (t == p) { // stack의 top이 자기 자신이면
                break; // 종료
            }
        }
        // 정렬
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
        scc_cnt++; // scc 갯수 증가
    }
    // 부모 값을 반환
    return parent;
}

bool compare(vector<int>& V1, vector<int>& V2) {
    return V1[0] < V2[0]; // 0번째 원소 기준 오름차순 정렬
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, E;
    cin >> V >> E;
    for (int i = 1; i <= E; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }

    // 각 정점에 대해 dfs를 시행 
    for (int i = 1; i <= V; i++) {
        if (parent_arr[i] == 0) { // 방문하지 않았으면
            dfs(i);
        }
    }
    // 출력
    cout << scc_cnt << "\n";
    // 정렬
    sort(SCC.begin(), SCC.end(), compare);
    for (int i = 0; i < scc_cnt; i++) {
        for (int j = 0; j < SCC[i].size(); j++) {
            cout << SCC[i][j] << " ";
        }
        cout << -1 << "\n";
    }

    return 0;
}