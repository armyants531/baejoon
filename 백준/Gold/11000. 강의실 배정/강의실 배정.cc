// 강의실 배정  // greedy  // priority queue
// https://wooono.tistory.com/393 참고
// 시작 시간을 기준으로 오름차순 정렬(시작 시간이 같을 때는 끝나는 시간을 기준으로 오름차순 정렬)
// 시작 시간이 가장 빠른 수업의 종료시간을 min_heap에 저장
// 이후 min_heap의 top과 다음 수업의 시작 시간을 비교하며 min_heap에 종료 시간을 push 
#include <bits/stdc++.h>

using namespace std;

// 수업 시간 정보 저장
vector<pair<int, int>> class_arr;
// 강의실에서 수업이 끝나는 시간 저장(최소 힙) 
priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {
	int N;
	cin >> N;
	int S, T;
	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		class_arr.push_back({ S, T });
	}
	sort(class_arr.begin(), class_arr.end());
	min_heap.push(class_arr[0].second); // 시작 시간이 가장 빠른 수업의 종료시간을 min_heap에 push
	for (int i = 1; i < N; i++) {
		if (min_heap.top() <= class_arr[i].first) { // 강의실의 수업 종료시간 중 최소 값 <= 현재 강의의 시작 시간
			// 원래 있던 강의실에 수업 추가
			min_heap.pop();
			min_heap.push(class_arr[i].second);
		} 
		else {
			// 강의실을 추가
			min_heap.push(class_arr[i].second);
		}
	}
	cout << min_heap.size() << "\n";
	return 0;
}