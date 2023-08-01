// 최소 회의실 개수
#include <bits/stdc++.h>
#define int long long
 
using namespace std;
using pii = pair<int, int>;
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<pii> arr;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		arr.push_back({x, y});
	}
	sort(arr.begin(), arr.end()); // 시작 시간 오름차순 
	int ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq; // min_heap, 끝나는 시간 저장 
	for (int i = 0; i < N; i++) {
		if (pq.empty()) {
			pq.push(arr[i].second);
		} 
		else {
			while (!pq.empty() && pq.top() <= arr[i].first) { // 이전 회의 끝나는 시간 <= 현 회의 시작 시간  
				pq.pop();
			}
			pq.push(arr[i].second);
		}
		ans = max(ans, (int)pq.size());
	}
	
	cout << ans << "\n";
 
	return 0;
}