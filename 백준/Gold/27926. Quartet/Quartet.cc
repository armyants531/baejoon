// Quartet  // greedy  // graph
// 자리 배치에서 조화도를 얻을 수 있는 경우를 고려
// 1. 가장 큰 시너지를 최대 2개 선택하는 것
// 2. 사이클이 아닌 인접한 3개의 간선으로 이루어진 경로 중 가중치 합이 최대인 것
#include <bits/stdc++.h>
#define int long long

using namespace std;

struct edge {
	int d;
	int u;
	int v;
};

vector<edge> arr; // 간선 배열

bool cmp(int a, int b) { // d값에 대해 내림차순으로 간선 번호 정렬
	return arr[a].d > arr[b].d;
}

bool cmp2(edge a, edge b) {
	return a.d > b.d;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int u, v, d;
	vector<vector<int>> point(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> d;
		arr.push_back({d, u, v});	
	}
	sort(arr.begin(), arr.end(), cmp2);
	for (int i = 0; i < M; i++) {
		point[arr[i].u].push_back(i); // 간선 번호 저장
		point[arr[i].v].push_back(i);
	}
	if (M == 0) {
		cout << 0 << "\n";
	}
	else if (M == 1) {
		cout << arr[0].d << "\n";
	}
	else if (M == 2) {
		cout << arr[0].d + arr[1].d << "\n";
	}
	else {
		int max_1 = 0; // 가장 큰 시너지를 최대 2개 선택하는 것
		int max_2 = 0; // 사이클이 아닌 인접한 3개의 간선으로 이루어진 경로 중 가중치 합이 최대인 것
		max_1 = arr[0].d + arr[1].d;
		// max2는 가운데 간선을 고정시켜 생각
		// 두 학생 사이의 시너지는 최대 하나만 주어진다
		// 따라서 가운데 간선과 인접한 간선 중 조화도가 큰 간선을 3개까지 고려하면 된다(먼저 2개를 고르고 사이클 이루는 경우 하나 더 고려).
		// 가운데 간선을 이루는 두 점과 이어진 간선을 각각 3개 고려한다.    
		// 1. 각 정점마다 가장 가중치가 큰 간선 3개를 찾기
		vector<vector<int>> A(N + 1); // 정점별로 가중치가 가장 큰 간선 저장하는 배열
		for (int i = 1; i <= N; i++) {
			int f = 0, s = 0, t = 0;
			int first = -1, second = -1, third = -1;
			for (auto a : point[i]) {
				if (arr[a].d > first) {
					t = s;
					s = f;
					f = a;
					third = second;
					second = first;
					first = arr[a].d;
				}
				else if (arr[a].d > second) {
					t = s;
					s = a;
					third = second;
					second = arr[a].d;
				}
				else if (arr[a].d > third) {
					t = a;
					third = arr[a].d;
				}
			}
			if (first != -1) {
				A[i].push_back(f);
			}
			if (second != -1) {
				A[i].push_back(s);
			}
			if (third != -1) {
				A[i].push_back(t);
			}
		}
		// 간선 i를 중간에 두고 양 끝에 배치할 간선 정하기
		for (int i = 0; i < M; i++) {
			// 간선 i를 이루는 점 u와 연결된 간선
			vector<int> u_line;
			for (int j = 0; j < A[arr[i].u].size(); j++) {
				if (i != A[arr[i].u][j]) {
					u_line.push_back(A[arr[i].u][j]);
				}
			}
			// 간선 i를 이루는 점 v와 연결된 간선
			vector<int> v_line;
			for (int j = 0; j < A[arr[i].v].size(); j++) {
				if (i != A[arr[i].v][j]) {
					v_line.push_back(A[arr[i].v][j]);
				}
			}
			sort(u_line.begin(), u_line.end(), cmp);
			sort(v_line.begin(), v_line.end(), cmp);
			int val = 0;
			if (u_line.size() > 0 && v_line.size() > 0) {
				int p, q; // 네 명 중 양 끝에 해당하는 두 명
				if (arr[u_line[0]].u == arr[i].u) {
					p = arr[u_line[0]].v;
				}
				else {
					p = arr[u_line[0]].u;
				}
				if (arr[v_line[0]].v == arr[i].v) {
					q = arr[v_line[0]].u;
				}
				else {
					q = arr[v_line[0]].v;
				}
				if (p == q) { // cycle 이룸 -> 다른 후보 선정
					val = max(arr[u_line[0]].d, arr[v_line[0]].d);
					if (u_line.size() >= 2) {
						val = max(val, arr[u_line[1]].d + arr[v_line[0]].d);
					}
					if (v_line.size() >= 2) {
						val = max(val, arr[u_line[0]].d + arr[v_line[1]].d);
					}
				}
				else {
					val = arr[u_line[0]].d + arr[v_line[0]].d;
				}
			}
			else if (u_line.size() > 0) {
				val = arr[u_line[0]].d;
			}
			else if (v_line.size() > 0) {
				val = arr[v_line[0]].d;
			}
			max_2 = max(max_2, arr[i].d + val);
		}	
		cout << max(max_1, max_2) << "\n";
	}

	return 0;
}