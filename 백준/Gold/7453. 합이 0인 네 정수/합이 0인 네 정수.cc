// 합이 0인 네 정수  // Meet in the middle
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> A, B, C, D;
vector<ll> AB, CD;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	ll a, b, c, d;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	// A와 B에서 각각 하나의 원소를 골라 더한 값을 저장하는 배열 AB
	// C와 D에서 각각 하나의 원소를 골라 더한 값을 저장하는 배열 CD
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}
	sort(CD.begin(), CD.end()); // CD 정렬
	ll cnt = 0;
	for (int i = 0; i < AB.size(); i++) {
		// upper_bound: 찾으려는 val(key) 값보다 큰 숫자가 배열 몇 번째에서 처음으로 등장하는지를 리턴(반환형: iterator)
		// lower_bound: 찾으려는 val(key) 값 이상인 숫자가 배열 몇 번째에서 처음으로 등장하는지를 리턴(반환형: iterator)
		cnt += upper_bound(CD.begin(), CD.end(), -AB[i]) - lower_bound(CD.begin(), CD.end(), -AB[i]); // CD의 원소 중 값이 -AB[i]인 원소 개수 더하기
	}
	cout << cnt << "\n";
}