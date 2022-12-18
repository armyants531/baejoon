// 소트  // greedy
// https://sunrinnote.tistory.com/143 참고
// 수를 하나 선택하고(단, 이전에 택한 수 + 1은 안됨), 나머지 수들로 수열을 만들 수 있으면 다음으로 넘어감
// 나머지 수들로 수열을 만들지 못하는 경우: 선택한 수와 선택한 수 + 1 만 남은 경우
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr;
	vector<int> num_cnt(1001); // 0 ~ 1000에 해당하는 수의 개수를 세는 배열
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		arr.push_back(val);
		num_cnt[val]++;
	}
	vector<int> num_list;
	for (int i = 0; i <= 1000; i++) {
		if (num_cnt[i] != 0) {
			num_list.push_back(i);
		}
	}
	vector<int> ans;
	int prev = -10; // 이전에 선택한 수
	for (int i = 0; i < N; i++) {
		int choose;
		for (int j = 0; j < num_list.size(); j++) {	
			// 수 선택하기
			if (prev + 1 != num_list[j] && num_cnt[num_list[j]]) {
				choose = num_list[j];
				num_cnt[num_list[j]]--;
				// 나머지 수들로 수열을 만들 수 없는지 확인
				bool isOtherEx = false;
				for (auto a : num_list) {
					if (num_cnt[a] != 0 && a != choose && a != (choose + 1)) {
						isOtherEx = true;
						break;
					}
				}
				if (isOtherEx) {
					break;
				}
				else { // 수 선택 취소
					num_cnt[num_list[j]]++;
					continue;
				}
			}
			else {
				continue;
			}
		}
		ans.push_back(choose);
		prev = choose; // 이전에 선택한 수를 갱신
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}