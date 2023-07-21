// 전봇대  // ternary search
// sigma(i*z - x_i) (z: 일정하게 떨어진 거리)
// 아래로 볼록한 형태의 그래프
// https://blog.naver.com/kks227/221432986308 참고
#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef long long ll;
int N;
vector<int> x;

int sigma(int z) {
	int sum = 0;
	for (int i = 1; i < N; i++) {
		sum += abs(i * z - x[i]);
	}
	return sum;
}

int tsearch(int low, int high) {
	while (low + 3 <= high) {
		int a = (low * 2 + high) / 3;
		int b = (low + high * 2) / 3;
		if (sigma(a) < sigma(b)) {
			high = b;
		}
		else {
			low = a;
		}
	}
	// [low, high] 내 최솟값 찾기
	int min_v = 100000000000000; // 10^14
	for (int z = low; z <= high; z++) {
		min_v = min(sigma(z), min_v);
	}
	return min_v;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	int low = 0;
	int high = x[N - 1];
	cout << tsearch(low, high) << "\n";
	
	return 0;
}