#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

string solve(string p, int n, string List) {
	deque<int> deq; // 시행 횟수가 여러 번일 수 있으므로 초기화를 위해 함수 내부 선언
	int len = p.length();
	int D_cnt = 0;
	bool rever = false; // 뒤집힌 여부 판단

	int List_len = List.length();
	// 두 자리 이상의 숫자가 입력 될 수 있음!
	string temp = ""; // deque에 넣을 예정인 문자열(숫자로 변환)
	for (int i = 1; i < List_len; i++) { // List[0] == '['
		if (List[i] >= '0' && List[i] <= '9') {
			temp += List[i];
		}
		else { // ',' or ']'
			if (!temp.empty()) { // 빈 리스트일 때 예외처리
				deq.push_back(stoi(temp)); // stoi: string을 int로 변환
				temp = ""; // temp 초기화
			}
		}
	}
	// AC언어 판단
	for (int i = 0; i < len; i++) {
		if (p[i] == 'D') {
			// check if number of D > n
			D_cnt++;
			if (D_cnt > n) {
				return "error";
			}
			if (rever) {
				deq.pop_back(); // 맨 뒤 제거
			}
			else {
				deq.pop_front(); // 맨 앞 제거
			}
		}
		else if (p[i] == 'R') {
			rever = !rever;
		}
	}
	// return 
	string str = "";
	str.append("[");
	if (rever) { // 뒤집혀있으면
		while (!deq.empty()) {
			int a = deq.back();
			str.append(to_string(a));
			str.append(",");
			deq.pop_back();
		}
		if (str != "[") { // deq가 비어있을 때 예외처리
			str.pop_back(); // 마지막 "," 제거
		}
	}
	else {
		while (!deq.empty()) {
			int a = deq.front();
			str.append(to_string(a));
			str.append(",");
			deq.pop_front();
		}
		if (str != "[") {
			str.pop_back(); // 마지막 "," 제거
		}	
	}
	str.append("]");
	return str;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string p, List;
		int n;
		cin >> p;
		cin >> n;
		cin >> List;

		cout << solve(p, n, List) << "\n";
	}

	return 0;
}