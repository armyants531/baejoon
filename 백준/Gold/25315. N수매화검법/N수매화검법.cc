#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> cnt(2501);

// CCW(counter clockwise)
// 세 점이 일직선 위에 있는 경우 x
struct coord { //coordinate
	ll x;
	ll y;
};

int CCW(coord A, coord B, coord C) {
	// overflow prevention
	// (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
	ll val = B.x * C.y - B.x * A.y - A.x * C.y - B.y * C.x + A.x * B.y + A.y * C.x;
	if (val > 0)
		return 1;
	else if (val < 0)
		return -1;
	else
		return 0;
}

int main() {
	int N;
	cin >> N;
	vector<ll> sx(N);
	vector<ll> sy(N);
	vector<ll> ex(N);
	vector<ll> ey(N);
	vector<ll> w(N);
	vector<bool> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> sx[i] >> sy[i] >> ex[i] >> ey[i] >> w[i];
	}
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			coord A, B, C, D;
			A = { sx[i], sy[i] };
			B = { ex[i], ey[i] };
			C = { sx[j], sy[j] };
			D = { ex[j], ey[j] };
			// AB를 기준으로 점 C, D의 CCW 확인
			int sign1 = CCW(A, B, C) * CCW(A, B, D);
			// CD를 기준으로 점 A, B의 CCW 확인
			int sign2 = CCW(C, D, A) * CCW(C, D, B);
			if (sign1 == -1 && sign2 == -1) { // 교차
				if (w[i] > w[j]) { // w 값이 작은 선분 배열에 다른 쪽 선분 번호 넣어줌
					cnt[j]++;
				}
				else {
					cnt[i]++;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		sum += (cnt[i] + 1) * w[i];
	}
	cout << sum << "\n";

	return 0;
}