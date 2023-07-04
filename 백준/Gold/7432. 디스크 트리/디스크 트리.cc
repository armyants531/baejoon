// 디스크 트리  // trie
// 디렉토리의 이름을 key값으로, 트라이 노드의 포인터를 value로 갖는 맵을 자식 노드로 구현
// https://allmymight.tistory.com/m/84 참고
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct TrieNode {
	bool is_end; // end point checker
	map<string, TrieNode*> child;
	map<string, TrieNode*>::iterator it;
	// constructor
	TrieNode() : is_end(false) {}
	// destructor
	~TrieNode() {
		for (it = child.begin(); it != child.end(); it++) {
			delete it->second;
		}
	}
	// 트라이에 경로를 삽입하는 함수
	void insert(vector<string> vec, int idx) {
		if (idx == vec.size()) { // 경로의 끝일 때
			is_end = true;
			return;
		}
		else {
			it = child.find(vec[idx]);
			if (it == child.end()) { // 찾지 못함
				TrieNode* node = new TrieNode; // 자식 노드 생성
				child[vec[idx]] = node;
				node->insert(vec, idx + 1); // 다음 문자 삽입
			}
			else { // 발견
				it->second->insert(vec, idx + 1); // 기존 노드를 타고 내려감 -> 다음 문자 삽입
			}
		}
	}
	// 트라이 출력
	void printTrie(int level) {
		if (!child.empty()) {
			for (it = child.begin(); it != child.end(); it++) {
				for (int i = 0; i < level; i++) {
					cout << " ";
				}
				cout << it->first << "\n";
				it->second->printTrie(level + 1);
			}
		}
		return;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	TrieNode* root = new TrieNode();
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		vector<string> vec;
		string str = "";
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '\\') {
				vec.push_back(str);
				str = "";
			}
			else {
				str += s[j];
			}
		}
		vec.push_back(str);
		root->insert(vec, 0);
	}
	root->printTrie(0);

	return 0;
}