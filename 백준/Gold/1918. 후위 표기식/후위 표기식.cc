// 후위 표기식  // stack
// 중위 표기식 -> 후위 표기식 변환 
#include <bits/stdc++.h>

using namespace std;

stack<char> st;

int Precedence(char oper) {
	if (oper == '*' || oper == '/')
		return 2;
	else if (oper == '+' || oper == '-')
		return 1;
	else // '('
		return 0;
}

// Infix를 postfix로 바꾸어 주는 함수
string InfixToPostfix(string infix) {
	string postfix;
	for (int i = 0; i < infix.length(); i++) {
		char c = infix[i];
		if (c == '(') { // 왼쪽 괄호가 나오면
			st.push(c); // 스택에 삽입
		}
		else if (c == ')') { // 오른쪽 괄호가 나오면
			while (st.top() != '(') { // 왼쪽 괄호가 나올 때까지 
				postfix += st.top();
				st.pop(); // top의 원소를 pop
			}
			// top에 남아있는 '('를 pop 
			st.pop();
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') { // 연산자가 나오면 
			// stack이 비어있지 않고 스택 top의 연산자의 우선순위가 더 크거나 같으면 top의 원소를 postfix에 추가하고 pop
			while ((!st.empty()) && (Precedence(st.top()) >= Precedence(c))) {
				postfix += st.top();
				st.pop(); 
			}
			st.push(c);
		}
		else { // 문자이면
			postfix += c;
		}
	}
	// 마지막 단계: postfix에 stack에 남아있는 모든 operator를 top에서부터 차례로 넣는다. 
	while (!st.empty()) {
		postfix += st.top();
		st.pop();
	}
	return postfix;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string infix, postfix;
	cin >> infix;
	postfix = InfixToPostfix(infix);
	cout << postfix << "\n";

	return 0;
}