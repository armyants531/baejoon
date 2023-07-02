#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> a;

bool possible(int mid, int N, int T) { // 최대 mid번 대여가능 
	vector<int> end(N); // 세미나의 끝 지점 기록 
	for (int i = 0; i < mid; i++) { // 0 ~ mid - 1까지는  
		int s = max(a[i] - T + 1, 1); // 1과 최대한 가깝게 
		int e = s + T - 1;
		if (e > a[i] + T - 1) { // 범위 초과 
			return false;
		}
		end[i] = e;
	}
	for (int i = mid; i < N; i++) { // mid ~ N - 1까지는  
		int s = max(a[i] - T + 1, end[i - mid] + 1); // i - mid번 이후로 배치 
		int e = s + T - 1;	
		if (e > a[i] + T - 1) {
			return false;
		}
		end[i] = e;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, T;
	cin >> N >> T;
	a.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];	
	}
	sort(a.begin(), a.end());
	int low = 1;
	int high = N;
	int mid;
	int mid_min = N;
	while (low <= high) {
		mid = (low + high) / 2;
		if (possible(mid, N, T)) {
			mid_min = min(mid_min, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << mid_min << "\n";
	
	return 0;	
}