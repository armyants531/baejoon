#include <bits/stdc++.h> 

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(N);
	map<int, int> mp;
	set<int> s;
	double sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		mp[arr[i]]++;
		sum += arr[i];
		s.insert(arr[i]);
	}
	int avg = round(sum / N);
	if (avg == 0) cout << 0 << "\n";
	else cout << avg << "\n";
	
	sort(arr.begin(), arr.end());
	cout << arr[N / 2] << "\n";
	int max_cnt = 0;
	deque<int> dq; // save val
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		int cnt = mp[*it];
		if (cnt == max_cnt) {
			dq.push_back(*it);
		}
		else if (cnt > max_cnt) {
			max_cnt = cnt;
			while (!dq.empty()) {
				dq.pop_back();
			}
			dq.push_back(*it);
		}
	}
	
	if (dq.size() >= 2) {
		cout << dq[1] << "\n";
	}
	else {
		cout << dq[0] << "\n";
	}
	cout << arr[N - 1] - arr[0] << "\n";
}