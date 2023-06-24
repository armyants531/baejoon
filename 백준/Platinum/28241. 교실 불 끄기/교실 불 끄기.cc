// 교실 불 끄기  // dp
// 각 층을 올라가고 내려가는 경우는 총 4가지 
// X[i] := i층과 i + 1층을 연결하는 상태가 X일 때 소비한 시간의 최솟값
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll INF = 10000000000000;

ll A[100001], B[100001], C[100001], D[100001]; // (오름, 내림)순 -> A: (left, left), B: (right, right), C(left, right), D(right, left)
ll gap[100001];
vector<ll> arr[100001];

ll tabulation(ll n, ll m) {
	A[0] = 0;
	B[0] = INF;
	C[0] = 0;
	D[0] = INF;
	for (int i = 1; i < n; i++) {
		int k = arr[i].size() - 2;
		A[i] = min({ A[i - 1] + 2 * arr[i][k], B[i - 1] + 2 * m + 2, C[i - 1] + m + 1, D[i - 1] + m + 1 });
		B[i] = min({ A[i - 1] + 2 * m + 2, B[i - 1] + 2 * m + 2 - 2 * arr[i][1], C[i - 1] + m + 1, D[i - 1] + m + 1 });
		C[i] = min({ A[i - 1] + m + 1, B[i - 1] + m + 1, C[i - 1] + 2 * (m + 1 - gap[i]), D[i - 1] + 2 * m + 2});
		D[i] = min({ A[i - 1] + m + 1, B[i - 1] + m + 1, C[i - 1] + 2 * m + 2, D[i - 1] + 2 * (m + 1 - gap[i])});
	}
	return min({ A[n - 1] + 2 * m, B[n - 1] + 2 * m, C[n - 1] + m + 1, D[n - 1] + m + 1 });
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		arr[i].push_back(0);
		ll a;
		for (int j = 0; j < k; j++) {
			cin >> a;
			arr[i].push_back(a);
		}
		arr[i].push_back(m + 1);
	}
	for (int i = 1; i < n; i++) {
		gap[i] = 0;
		for (int j = 0; j < arr[i].size() - 1; j++) {
			gap[i] = max(gap[i], arr[i][j + 1] - arr[i][j]);
		}
	}
	cout << tabulation(n, m) + 2 * (n - 1) << "\n";
	/*
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << B[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << C[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << D[i] << " ";
	}
	cout << "\n";
	*/
	return 0;
}