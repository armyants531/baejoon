// 전화번호 목록  // trie 풀이
// https://twpower.github.io/187-trie-concept-and-basic-problem 참고(trie 구현)
#include <bits/stdc++.h>
#define ALPHA 10 // 0 ~ 9

using namespace std;
typedef long long ll;
char phone[10000][11];

struct TrieNode {
	bool is_end; // end point checker
	TrieNode* child[ALPHA]; 
	// constructor
	TrieNode() : is_end(false) {
		memset(child, 0, sizeof(child));
	}
	// destructor
	~TrieNode() {
		for (int i = 0; i < ALPHA; ++i) {
			if (child[i]) delete child[i];
		}
	}

	// 트라이에 key 문자열을 삽입하는 함수
	void insert(const char* key) {
		if (*key == '\0') { // 문자열 끝일 때
			is_end = true;
		}
		else {
			int curr = *key - '0';
			if (child[curr] == 0) { // 탐색이 처음되는 지점일 경우
				child[curr] = new TrieNode(); // 동적할당으로 자식노드 생성
			}
			child[curr]->insert(key + 1); // 다음 문자를 삽입
		}
	}
	
	// key 문자열이 포함되어 있는지 확인하는 함수
	bool str_exist(const char* key) {
		if (*key == '\0') {
			return true;
		}
		if (is_end) {
			return false;
		}
		int curr = *key - '0';
		return child[curr]->str_exist(key + 1);
	}
};

int main() {
	
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;	
		TrieNode* root = new TrieNode();
		for (int i = 0; i < N; i++) {
			cin >> phone[i];
			root->insert(phone[i]);
		}
		bool consistence = true;
		for (int i = 0; i < N; i++) {
			if (!root->str_exist(phone[i])) {
				consistence = false;
				break;
			}
		}
		if (consistence) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
		delete root;
	}

	return 0;
}