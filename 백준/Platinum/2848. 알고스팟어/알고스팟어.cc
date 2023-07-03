// 알고스팟어  // 위상정렬
// 사이클이 있는 경우 위상정렬 결과 배열의 크기가 노드 개수보다 작다
// queue에 들어 있는 노드는 indegree가 0 -> queue의 크기가 2 이상인 경우가 생기면 위상정렬 경우의 수가 2가지 이상 
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(26);
vector<int> indegree(26); // 0 ~ 25(a ~ z)
vector<int> ans(26);
vector<bool> exist(26); // 알파벳 존재 여부 기록

int topologySort(int cnt) {
	queue<int> que;
	bool multi = false; // 위상정렬이 여러가지인가?
	for (int i = 0; i < 26; i++) {
		if (exist[i] && indegree[i] == 0) {
			que.push(i);
		}
	}
	for (int i = 0; i < cnt; i++) {
		if (que.empty()) { // que가 중간에 비어있으면 불가능(사이클 존재)
			return 1;
		}
		if (que.size() >= 2) {
			multi = true;
		}
		int node = que.front();
		que.pop();
		ans[i] = node;
		for (auto next : adj[node]) { // 인접한 노드를 순회하며 indegree 1씩 감소
			indegree[next]--;
			if (indegree[next] == 0) {
				que.push(next);
			}
		}
	}
	if (multi) {
		return 2;
	}
	else {
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<string> s(N);
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++) {
			exist[s[i][j] - 'a'] = true;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (exist[i]) {
			cnt++;
		}
	}
	int res = 0;
	for (int i = 1; i < N; i++) {	
		for (int j = 0; j < min(s[i - 1].size(), s[i].size()); j++) {
			if (s[i - 1][j] != s[i][j]) {
				int a = s[i - 1][j] - 'a'; // a가 b보다 앞에 옴
				int b = s[i][j] - 'a';
				adj[a].push_back(b);
				indegree[b]++;
				break;
			}
			// abc, ab 같은 입력에 관한 예외처리
			if (j == s[i].size() - 1 && s[i - 1].size() > s[i].size()) {
				res = 1;
				break;
			}
		}
		if (res == 1) break;
	}
	if (res != 1) res = topologySort(cnt);
	
	if (res == 1) {
		cout << '!' << "\n";
	}
	else if (res == 2) {
		cout << '?' << "\n";
	}
	else {
		for (int i = 0; i < cnt; i++) {
			cout << (char)('a' + ans[i]);
		}
		cout << "\n";
	}
}