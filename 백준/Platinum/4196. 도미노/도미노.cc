// 도미노  // SCC
// SCC 중에서 indegree가 0인 것의 갯수를 구해주면 됨
// SCC마다 고유 id를 붙여주고 인접 리스트에서 두 노드가 
// https://hyeo-noo.tistory.com/134 참고
#include <bits/stdc++.h>

using namespace std;

int id; // 노드별 고유 id
int scc_cnt; // SCC 갯수
vector<int> parent_arr(100001, 0); // 처음 설정된 id 저장하는 리스트(부모 저장), 처음에는 0으로 초기화
vector<bool> finished(100001, 0); // 노드별 dfs 종료 여부 기록
vector<vector<int>> adj; // adjacent list 
stack<int> st;
vector<int> SCC_ID(100001); // 각 노드의 SCC id를 저장(0 ~ scc_cnt - 1)
vector<int> SCC_Indegree(100000); // SCC의 indegree 저장(index: SCC의 id)

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
		while (true) {
			int t = st.top();
			st.pop();
			finished[t] = true;
			SCC_ID[t] = scc_cnt; // 노드가 속한 SSC의 id를 이전까지의 SSC 개수로 설정
			if (t == x) {
				break;
			}
		}
		scc_cnt++;
	}

	return parent;
}

void init(int N) {
	fill(parent_arr.begin(), parent_arr.begin() + N + 1, 0);
	fill(finished.begin(), finished.begin() + N + 1, false);
	fill(SCC_Indegree.begin(), SCC_Indegree.begin() + N, 0);
	adj.clear();
	adj.resize(N + 1, vector<int>());
	id = 1; // 노드별 고유 id 초기화
	scc_cnt = 0; // SCC 갯수 초기화
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int a = 0; a < T; a++) {
		int N, M;
		cin >> N >> M;
		
		init(N);
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
				}
			}
		}
		
		// indegree가 0인 SCC 갯수 세기
		int cnt = 0;
		for (int i = 0; i < scc_cnt; i++) {
			if (SCC_Indegree[i] == 0) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}