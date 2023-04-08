// 강의실 2  // greedy  // priority queue
#include <bits/stdc++.h>

using namespace std;

struct lec {
	int s;
	int e;
	int n;
};

/*
struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.first > b.first; // 작은 값 우선 
	}
};
*/

bool comp(lec a, lec b) {
	return a.s < b.s; // 작은 값 우선
}

vector<lec> classes; // 수업의 시작, 끝 시간, 수업 번호 저장
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap; // {수업 끝나는 시간, 강의실 번호} 저장하는 최소 힙
vector<int> class_num; // 강의마다 배정된 강의실 번호 기록

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	class_num.resize(N + 1);
	int n, s, e; // 강의 번호, 시작 시간, 종료 시간
	for (int i = 0; i < N; i++) {
		cin >> n >> s >> e;
		classes.push_back({ s, e, n });
	}
	sort(classes.begin(), classes.end(), comp); // 수업 시작 시간에 대해 오름차순 정렬
	class_num[classes[0].n] = 1; // 강의실 번호 기록
	min_heap.push({ classes[0].e, 1 }); // 시작 시간이 가장 빠른 수업의 종료시간을 min_heap에 push
	
	for (int i = 1; i < N; i++) {
		if (min_heap.top().first <= classes[i].s) { // 원래 강의실에 수업 추가 가능
			class_num[classes[i].n] = min_heap.top().second; // 강의실 번호 기록
			min_heap.pop();
			min_heap.push({ classes[i].e, class_num[classes[i].n] });
		} 
		else { // 강의실 개수 추가
			class_num[classes[i].n] = min_heap.size() + 1; // 강의실 번호 기록
			min_heap.push({ classes[i].e, min_heap.size() + 1 });
		} 
	}
	cout << min_heap.size() << "\n";
	for (int i = 1; i <= N; i++) {
		cout << class_num[i] << "\n";
	}
}