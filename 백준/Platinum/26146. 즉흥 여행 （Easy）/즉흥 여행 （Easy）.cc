#include <bits/stdc++.h>

using namespace std;

int id = 1; // 노드별 고유 id
int scc_cnt = 0; // SCC 갯수
vector<int> parent_arr(200001, 0); // 처음 설정된 id 저장하는 리스트(부모 저장), 처음에는 0으로 초기화
bool finished[200001] = { false, };
vector<vector<int>> SCC; // SCC 저장
vector<int> adj[200001]; // adjacent list 
stack<int> st;

int dfs(int p) {
	parent_arr[p] = id;
	id++;
	st.push(p);

	int parent = parent_arr[p]; // 처음에는 부모노드를 id로 설정
	for (int i = 0; i < adj[p].size(); i++) { // 인접 노드 탐색
		int q = adj[p][i];
		if (parent_arr[q] == 0) { // q를 방문하지 않은 경우
			parent = min(parent, dfs(q));
		}
		else if (!finished[q]) { // q가 방문한 노드인데, 아직 dfs를 실행 중인 노드라면
			parent = min(parent, parent_arr[q]);
		}
	}

	if (parent == parent_arr[p]) { // 부모가 자기 자신이면
		vector<int> scc;
		while (true) {
			int t = st.top();
			finished[t] = true;
			st.pop();
			scc.push_back(t);
			if (t == p) {
				break;
			}
		}
		SCC.push_back(scc);
		scc_cnt++;
	}
	return parent;
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
	// 1번 노드에서 시작
	dfs(1);
	if (SCC[0].size() == V) { // scc의 크기와 노드 갯수가 같으면
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";
	}

	return 0;
}