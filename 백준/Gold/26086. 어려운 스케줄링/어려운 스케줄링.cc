// 어려운 스케줄링  // sort  // offline query  // deque
// 정렬은 맨 마지막 정렬만 처리해주면 됨
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, Q, k;
	cin >> N >> Q >> k;
	deque<int> deq;
	vector<vector<int>> input_arr(Q, vector<int>(2));
	bool isback = true;
	int order;
	// 입력 결과 저장
	int cnt1 = 0; // 1번 명령 카운트
	for (int i = 0; i < Q; i++) {
		cin >> order;
		input_arr[i][0] = order;
		if (order == 0) {
			int p;
			cin >> p;
			input_arr[i][1] = p;
		}
		else if (order == 1) {
			cnt1++;
		}
	}
	// 업무 처리 순서 정하기
	int cnt1_check = 0;
	for (int i = 0; i < Q; i++) {
		order = input_arr[i][0];
		if (order == 0) {
			int p = input_arr[i][1];
			if (isback) {
				deq.push_back(p);
			}
			else {
				deq.push_front(p);
			}
		}
		else if (order == 1) {
			cnt1_check++;
			if (cnt1 == cnt1_check) {
				if (isback) {
					// 내림차순 정렬
					sort(deq.begin(), deq.end(), greater<int>());
				}
				else {
					// 오름차순 정렬
					sort(deq.begin(), deq.end());
				}
			}
		}
		else { // order == 2
			isback = !isback; // 순서 뒤집기
		}
	}

	// deque은 인덱스로 원소 접근 가능
	if (isback) {
		cout << deq[deq.size() - k] << "\n";
	}
	else {
		cout << deq[k - 1] << "\n";
	}

	return 0;
}