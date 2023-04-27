// 괄호 추가하기 2  // brute force
// 후위표기식을 이용
// https://todaycode.tistory.com/73 참고(배경지식)
// https://jaimemin.tistory.com/1455 참고
#include <bits/stdc++.h>

using namespace std;

map<char, int> priority;
vector<char> parenthesis; // 괄호가 쳐진 숫자 위치 표시
int max_val = -2147483647;
int N;
string s;

// 후위연산식 계산
int postfixCal(string str) { // str: 후위연산식
    stack<int> st;
    for (int i = 0; i < N; i++) {
        if (str[i] >= '0' && str[i] <= '9') {  // 피연산자를 스택에 삽입
            st.push(str[i] - '0'); // char -> int
        }
        else if (st.size() > 1) { // 연산자가 나왔을 때 stack에서 두 개를 뽑아 계산
            int num;
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            if (str[i] == '+') {
                num = num1 + num2;
            }
            else if (str[i] == '-') {
                num = num1 - num2;
            }
            else if (str[i] == '*') {
                num = num1 * num2;
            }
            st.push(num);
        }
    }
    return st.top();
}

// 중위연산식을 후위연산식으로  바꾼 후  계산
int cal() {
    // infix -> postfix
    string str;
    stack<char> st;
    for (int i = 0; i < N; i++) {
        if (s[i] >= '0' && s[i] <= '9') { // 피연산자
            str += s[i];
        }
        switch (parenthesis[i]) {
        case '(': // 여는 괄호 
            st.push('(');
            break;
        case ')': // 닫는 괄호 
            while (st.top() != '(') { // 여는 괄호가 나올 때까지  pop   
                str += st.top();
                st.pop();
            }
            st.pop(); // 여는 괄호 
            break;
        default:
            if (s[i] >= '0' && s[i] <= '9') break; // 피연산자
            // 연산자
            // s[i] 연산자 우선순위가 스택 탑보다 더 커질 때까지
            while (!st.empty() && priority[st.top()] >= priority[s[i]]) {
                if (st.top() == '(') { // 스택 top에 열린 괄호가 오면 멈춤
                    break;
                }
                str += st.top();
                st.pop();
            }
            st.push(s[i]); // 연산자 삽입
            break;
        }
    }
    while (!st.empty()) {
        str += st.top();
        st.pop();
    }
    // 후위연산 계산 후 리턴
    //cout << str << ' ' << postfixCal(str) << "\n";
    return postfixCal(str);
}

// 재귀를 통해 괄호치기
void sol(int idx) {
    if (idx >= N) {
        max_val = max(max_val, cal());
        return;
    }
    for (int i = idx; i < N; i += 2) {
        if (i >= N - 2) {
            sol(i + 2);
        }
        else if (parenthesis[i] != '(' && parenthesis[i] != ')' && parenthesis[i + 2] != '(' && parenthesis[i + 2] != ')') {
            parenthesis[i] = '(';
            parenthesis[i + 2] = ')';
            sol(i + 2);
            parenthesis[i] = ' ';
            parenthesis[i + 2] = ' ';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> s;
    priority['('] = 3;
    priority['*'] = 2;
    priority['-'] = 1;
    priority['+'] = 1;
    parenthesis.resize(N + 1);
    sol(0);
    cout << max_val << "\n";

    return 0;
}