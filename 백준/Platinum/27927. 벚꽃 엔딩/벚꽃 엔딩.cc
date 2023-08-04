// 벚꽃 엔딩  // two-pointer  // sweeping
#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int S, E;
	vector<pii> arr(N + 1);
	vector<pii> c; // 가장 많은 벚나무가 일렬로 연속해서 핀 날의 구간 저장 
	for (int i = 0; i < N; i++) {
		cin >> S >> E;
		arr[i] = { S, E };
	}
	// [i, j] 구간 투 포인터
	int i = 0;
	int j = 0;
	int max_cnt = 0;
	multiset<int> s, e; // 중복된 값이 들어올 수 있음!
	s.insert(arr[j].first);
	e.insert(arr[j].second);
	while (j < N) {
		auto max_s = s.rbegin();
		auto min_e = e.begin();
		int maxS = *max_s;
		int minE = *min_e;
		// 구간 내 S 최댓값과 E 최솟값 비교
		if (maxS > minE) { // 안 겹치는 부분 발생
			//cout << "1: " << i << " " << j << "\n";
			s.erase(s.find(arr[i].first)); // 원소 하나만 삭제
			e.erase(e.find(arr[i].second));
			i++;
		}
		else {
			//cout << "2: " << i << " " << j << "\n";
			if (max_cnt == j - i + 1) {
				c.push_back({ maxS, minE }); // 최대 연속 구간([maxS, minE])을 삽입
			}
			else if (max_cnt < j - i + 1) {
				max_cnt = j - i + 1; // 연속해서 핀 벚나무 개수 최댓값 갱신
				c.clear();
				c.push_back({ maxS, minE }); // 최대 연속 구간([maxS, minE])을 삽입
			}
			j++;
			s.insert(arr[j].first);
			e.insert(arr[j].second);
		}
	}
	// 가장 많은 벚나무가 일렬로 연속해서 핀 날을 중복 없이 세기(=2170번)
	sort(c.begin(), c.end());
	int len = 0;
	int left = c[0].first;
	int right = c[0].second;
	for (int i = 1; i < c.size(); i++) {
		if (right >= c[i].first) {
			right = max(right, c[i].second);
		}
		else {
			len += right - left + 1;
			left = c[i].first;
			right = c[i].second;
		}
	}
	len += right - left + 1;
	cout << max_cnt << " " << len << "\n";

	return 0;
}