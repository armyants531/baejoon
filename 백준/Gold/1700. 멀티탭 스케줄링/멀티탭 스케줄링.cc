// 멀티탭 스케줄링  // greedy
// 멀티탭을 꽉 채운 후, 그 이후에 사용하지 않을 멀티탭의 플러그를 뽑고, 
// 그럴 수 없는 경우에는 가장 마지막에 쓰일 용품의 플러그를 뽑고, 다음 전기용품을 사용한다.
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> num_of_ele(K+1, 0); // 각 기기별 남은 사용 횟수 
	vector<int> arr; // input
	vector<bool> multi_tap(101, false); // 플러그 사용 유무
	vector<int> using_plug; // 현재 사용 중인 플러그
	int cnt = 0; // 교체 횟수

	for (int i = 0; i < K; i++) {
		int ele;
		cin >> ele;
		arr.push_back(ele);
		num_of_ele[ele]++;
	}
	
	for (int i = 0; i < K; i++) {
		int ele = arr[i];
		if (using_plug.size() < N) { // 멀티탭이 비어있을 때
			if (multi_tap[ele]) { // 이미 꽂혀 있는 경우
				num_of_ele[ele]--;
			} 
			else { // 안 꽂힌 경우
				multi_tap[ele] = true;
				using_plug.push_back(ele);
				num_of_ele[ele]--;
			}
		}
		else { // 멀티탭이 꽉 차있을 때
			if (!multi_tap[ele]) { // 안 꽂힌 경우
				// 이후에 사용하지 않을 플러그 제거
				int remove = -1;
				for (int j = 0; j < N; j++) {
					if (num_of_ele[using_plug[j]] == 0) {
						remove = j;
						break;
					}
				}
				// 사용 안하는 플러그가 없는 경우
				if (remove == -1) {
					// 가장 나중에 사용하는 플러그의 인덱스 찾기
					int max_length = -1;
					int idx = 0;
					for (int k = 0; k < N; k++) {
						for (int j = i + 1; j < K; j++) {
							if (arr[j] == using_plug[k]) {
								if (max_length < j) { // 길이 갱신
									max_length = j;
									// 최대 길이 갱신 시 인덱스 갱신
									idx = k;
								}
								break;
							}
						}
					}
					remove = idx;
				}
				multi_tap[using_plug[remove]] = false; // 멀티탭에서 제거	
				using_plug[remove] = ele; // 멀티탭 갱신
				multi_tap[ele] = true; // 멀티탭에 추가
				cnt++;
				num_of_ele[ele]--;
				/*
				for (int i = 0; i < using_plug.size(); i++) { // test code
					std::cout << using_plug[i] << " ";
				}
				std::cout << "\n";
				*/
			}
			else { // 이미 꽂혀 있는 경우
				num_of_ele[ele]--;
			}
		}
	}
	
	std::cout << cnt << "\n";

	return 0;
}