// 오아시스 재결합  // stack
// https://everenew.tistory.com/89 참고
// stack에는 h에 대해 내림차순으로 저장
// 1. st.top().h < current : current 다음에 나오는 사람은 top을 볼 수 없으므로, top을 pop하고 cnt += st.top().same을 한다. 이를 st.top().h >= current가 될 때까지 반복한다.
// 2. st.top().h == current : current는 같은 키 가지는 사람들과 모두 쌍을 지을 수 있으므로 cnt += st.top().second, st.size() > st.top().same인 경우 current 보다 키 큰 사람이 스택에 존재하므로 cnt++(존재하는 키 큰 사람 중 맨 뒤 사람이랑 짝을 맺을 수 있음) 이후 st.pop()
// 3. st.top().h > current : current는 top과만 쌍을 지을 수 있다. cnt++;  
// 이후 current info를 push
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct info {
	ll h; // 키
	ll same; // 현재 스택에 들어있는 키가 h로 같은 사람 수
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	cin >> N;
	stack<info> st;
	ll cnt = 0;
	ll current;
	cin >> current;
	st.push({ current, 1 }); // 처음에 push
	for (int i = 1; i < N; i++) {
		cin >> current;
		while (!st.empty() && st.top().h < current) {
			cnt += st.top().same;
			st.pop();
		}
		if (!st.empty() && st.top().h == current) {
			ll incre = st.top().same;
			cnt += incre;
			if (st.size() > 1) { // 1보다 스택의 사이즈가 크면 더 큰 키 존재
				cnt++;
			}
			st.pop();
			st.push({ current, incre + 1 });
		}
		else if (!st.empty() && st.top().h > current) {
			cnt++;
			st.push({ current, 1 });
		}
		else { // st.empty()
			st.push({ current, 1 });
		}
	}
	
	std::cout << cnt << "\n";
	
	return 0;
}