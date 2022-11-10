// 트리 순회  // tree
// https://github.com/fpdjsns/Algorithm/blob/master/tip/%ED%8A%B8%EB%A6%AC%EC%88%9C%ED%9A%8C.cpp 참고
#include <bits/stdc++.h>

using namespace std;

typedef struct node {
	char name; // node name
	struct node* left; // left child node
	struct node* right; // right child node
} node;

void set_node(char name, node* n, node* left, node* right) {
	n -> name = name;
	n -> left = left;
	n -> right = right;
}

// 전위 순회
void pre_order(node* root) {
	cout << root->name;
	if (root->left)
		pre_order(root->left);
	if (root->right)
		pre_order(root->right);
}

// 중위 순회
void in_order(node* root) {
	if (root->left)
		in_order(root->left);
	cout << root->name;
	if (root->right)
		in_order(root->right);
}

// 후위 순회
void post_order(node* root) {
	if (root->left)
		post_order(root->left);
	if (root->right)
		post_order(root->right);
	cout << root->name;
}

int main() {
	int n;
	cin >> n;
	node arr[26];
	node* nodeArr[26];
	for (int i = 0; i < 26; i++) {
		arr[i] = { 'a', NULL, NULL };
		nodeArr[i] = &arr[i];
	}

	char name, left, right;
	for (int i = 0; i < n; i++) {
		cin >> name >> left >> right;
		if (left == '.' && right == '.')
			set_node(name, nodeArr[name - 'A'], NULL, NULL);
		else if (right == '.')
			set_node(name, nodeArr[name - 'A'], nodeArr[left - 'A'], NULL);
		else if (left == '.')
			set_node(name, nodeArr[name - 'A'], NULL, nodeArr[right - 'A']);
		else
			set_node(name, nodeArr[name - 'A'], nodeArr[left - 'A'], nodeArr[right - 'A']);
	}
	pre_order(nodeArr[0]);
	cout << "\n";
	in_order(nodeArr[0]);
	cout << "\n";
	post_order(nodeArr[0]);
	cout << "\n";

	return 0;
}