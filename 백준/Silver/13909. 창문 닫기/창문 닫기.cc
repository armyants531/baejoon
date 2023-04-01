// 창문 닫기
// N = 16
// 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 1
// N 보다 작고 가장 가까운 제곱근을 찾으면 된다. 
#include <bits/stdc++.h>

using namespace std;
typedef long long ll; 
ll N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	ll s = sqrt(N);
	cout << s << "\n";
	return 0;
}