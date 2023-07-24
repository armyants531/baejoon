// 즉흥 여행 (Hard)  // SCC  // Topological sort
#include <bits/stdc++.h>

using namespace std;

int id = 1; // 노드별 고유 id
int scc_cnt = 0; // SCC 갯수
vector<int> parent_arr(200001, 0); // 처음 설정된 id 저장하는 리스트(부모 저장), 처음에는 0으로 초기화
vector<bool> finished(200001); // 노드별 dfs 종료 여부 기록
vector<int> adj[200001]; // adjacent list 
stack<int> st;
vector<int> SCC_ID(200001); // 각 노드의 SCC id를 저장(0 ~ scc_cnt - 1)
vector<int> SCC_Indegree(200001); // SCC의 indegree 저장(index: SCC의 id)
vector<vector<int>> SCC; // SCC 저장
vector<int> SCC_adj[200001]; // SCC adjacent list(SCC id를 노드로 저장)
int ans_id; // 답에 해당하는 SCC id

int dfs(int x) {
	parent_arr[x] = id;
	id++;
	st.push(x);
	int parent = parent_arr[x];
	for (int i = 0; i < adj[x].size(); i++) {
		int y = adj[x][i];
		if (parent_arr[y] == 0) { // 방문을 하지 않았으면
			parent = min(parent, dfs(y));
		}
		else if (finished[y] == false) { // dfs가 진행 중이면
			parent = min(parent, parent_arr[y]);
		}
	}

	if (parent == parent_arr[x]) {
		vector<int> scc;
		while (true) {
			int t = st.top();
			st.pop();
			scc.push_back(t);
			finished[t] = true;
			SCC_ID[t] = scc_cnt; // 노드가 속한 SSC의 id를 이전까지의 SSC 개수로 설정
			if (t == x) {
				break;
			}
		}
		SCC.push_back(scc);
		scc_cnt++;
	}

	return parent;
}

// SCC 요소들 간의 위상정렬 중 큐에 두 개 이상 들어오는 경우 탐색
bool topologySort(int n) {
	queue<int> que;
	for (int i = 0; i < scc_cnt; i++) {
		if (SCC_Indegree[i] == 0) {
			que.push(i);
			ans_id = i;
		}
	}
	for (int i = 0; i < scc_cnt; i++) {
		if (que.empty()) { // cycle exists(이 문제는 해당 없음)
			return false;
		}
		if (que.size() >= 2) return false;
		int node = que.front();
		que.pop();
		for (auto next : SCC_adj[node]) {
			SCC_Indegree[next]--;
			if (SCC_Indegree[next] == 0) {
				que.push(next);
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
	}
	for (int i = 1; i <= N; i++) {
		if (parent_arr[i] == 0) {
			dfs(i);
		}
	}
	// SCC별로 indegree 구하기
	for (int i = 1; i <= N; i++) { // i -> adj[i][j] 
		for (int j = 0; j < adj[i].size(); j++) {
			if (SCC_ID[i] != SCC_ID[adj[i][j]]) {
				// adj[i][j]가 속한 SCC의 indegree 증가
				SCC_Indegree[SCC_ID[adj[i][j]]]++;
				SCC_adj[SCC_ID[i]].push_back(SCC_ID[adj[i][j]]);
			}
		}
	}
	// indegree를 이용해 위상정렬을 하는 도중 큐의 크기가 2 이상이 되면 안 됨(indegree = 0인 SCC가 여러 개 있는 것, 두 갈래로 나뉘는 것 등등)
	if (!topologySort(N)) {
		cout << 0 << "\n";
	}
	else {
		vector<int> ele;
		for (auto e : SCC[ans_id]) {
			ele.push_back(e);
		}
		sort(ele.begin(), ele.end());
		cout << ele.size() << "\n";
		for (auto e : ele) {
			cout << e << " ";
		}
		cout << "\n";
	}
	
	return 0;
}