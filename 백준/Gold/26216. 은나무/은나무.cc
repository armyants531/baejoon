// 은나무  // tree  // math  // Lowest Common Ancestor
// 파란 노드 사이 거리는 흰 부모 사이 거리 + 2 이다
// 부모 노드 번호 구하는 규칙
// 1. 파란 노드의 부모 번호: 노드 번호 / pow(K + 1, 부모 노드 높이 + 1)
// 2. 하얀 노드의 부모 번호: 노드 번호 / (K + 1)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll K;
	int H, Q;
	cin >> K >> H >> Q;
	ll blue = pow(K + 1, H) - 1;

	for (int i = 0; i < Q; i++) {
		ll A, B;
		cin >> A >> B;
		if (A > blue || B > blue) {
			cout << -1 << "\n";
		}
		else if (A == B) {
			cout << 0 << "\n";
		}
		else { // 두 수가 K + 1로 몇 번 나누어 떨어지는지로 부모 노드의 깊이 구하기
			int d1 = H - 1;
			int d2 = H - 1;
			ll A_C = A;
			ll B_C = B;
			while (A_C % (K + 1) == 0) {
				A_C /= (K + 1);
				d1--;
			}
			while (B_C % (K + 1) == 0) {
				B_C /= (K + 1);
				d2--;
			}
			// 거리는 2로 시작
			int dist = 2;
			// 두 노드 각각의 부모 노드 번호 구하기
			ll p1 = pow(K + 1, H - d1); // H - d1: 부모 노드의 높이 + 1
			ll num1 = A / p1; // 파란 노드의 부모 번호 구하기
			ll p2 = pow(K + 1, H - d2);
			ll num2 = B / p2;
			// 깊이 같게 만들기
			while (d1 > d2) {
				// 흰 노드의 부모 번호 구하기
				num1 = num1 / (K + 1);
				dist++;
				d1--;
			}
			while (d2 > d1) {
				num2 = num2 / (K + 1);
				dist++;
				d2--;
			}
			// LCA 찾기
			while (num1 != num2) {
				num1 = num1 / (K + 1);
				num2 = num2 / (K + 1);
				dist += 2;
			}
			cout << dist << "\n";
		}
	}
	return 0;
}