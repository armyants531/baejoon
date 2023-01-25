// 더 어려운 스케줄링  // deque  // set
// 3번 명령 직전의 1번 명령을 시행해야 한다
#include <bits/stdc++.h>

using namespace std;

struct info {
	int begin;
	int end;
	bool isback;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	deque<int> dq1; // 뒤집기 연산이 짝수 번(앞쪽)
	deque<int> dq2; // 뒤집기 연산이 홀수 번(뒤쪽)
	bool isback = false;
	int order;
	set<int> set; // 오름차순 정렬
	for (int i = 0; i < Q; i++) {
		cin >> order;
		if (order == 0) {  // 고유번호가 p인 업무를 스케줄러에 추가
			int p;
			cin >> p;
			if (isback) {
				dq2.push_front(p); // 뒤쪽을 관리하는 덱에 추가
			}
			else {
				dq1.push_front(p); // 앞쪽을 관리하는 덱에 추가
			}
		}
		else if (order == 1) { // 스케줄러에 들어있는 업무를 고유번호 값 기준으로 오름차순으로 정렬
			// 덱의 원소를 모두 set에 넣기
			while (!dq1.empty()) {
				set.insert(dq1.front());
				dq1.pop_front();
			}
			while (!dq2.empty()) {
				set.insert(dq2.front());
				dq2.pop_front();
			}
			// 정렬 시 뒤집기 연산은 초기화 됨
			isback = false;
		}
		else if (order == 2) { // 순서 뒤집기
			isback = !isback;
		}
		else { // order == 3, 스케줄러에 있는 업무 중 가장 앞에 위치한 업무를 꺼내어 처리하고, 그 고유번호 값을 출력
			if (isback) {
				if (!dq2.empty()) {
					cout << dq2.front() << "\n";
					dq2.pop_front();
				}
				else if (!set.empty()) {
					auto iter = set.end();
					iter--;
					cout << *iter << "\n"; // set의 최댓값 출력
					set.erase(iter); // 맨 뒤 삭제
				}
				else {
					cout << dq1.back() << "\n";
					dq1.pop_back();
				}
			}
			else { // front
				if (!dq1.empty()) {
					cout << dq1.front() << "\n";
					dq1.pop_front();
				}
				else if (!set.empty()) {
					cout << *set.begin() << "\n"; // set의 최솟값 출력
					set.erase(set.begin()); // 맨 앞 삭제
				}
				else {
					cout << dq2.back() << "\n";
					dq2.pop_back();
				}
			}
		}
	}

	return 0;
}