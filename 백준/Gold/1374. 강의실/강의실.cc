// 강의실  // greedy  // priority queue
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> classes; // 수업의 시작, 끝 시간 저장
priority_queue<int, vector<int>, greater<int>> min_heap; // 수업 끝나는 시간 저장하는 최소 힙

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int n, s, e;
	for (int i = 0; i < N; i++) {
		cin >> n >> s >> e;
		classes.push_back({ s, e });
	}
	sort(classes.begin(), classes.end()); // 수업 시작 시간에 대해 오름차순 정렬
	min_heap.push(classes[0].second); // 시작 시간이 가장 빠른 수업의 종료시간을 min_heap에 push
	for (int i = 1; i < N; i++) {
		if (min_heap.top() <= classes[i].first) { // 원래 강의실에 수업 추가 가능
			min_heap.pop();
			min_heap.push(classes[i].second);
		}
		else { // 강의실 개수 추가
			min_heap.push(classes[i].second);
		}
	}
	cout << min_heap.size() << "\n";
}