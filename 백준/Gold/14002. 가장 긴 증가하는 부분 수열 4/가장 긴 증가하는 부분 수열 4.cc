// 가장 긴 증가하는 부분 수열 4  // binary search  // LIS
#include <bits/stdc++.h>

using namespace std;

vector<int> vec;
vector<int> input;
vector<int> idx(1000001, 0); // save the each array element's index in the vec 
stack<int> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, len = 0;
	cin >> N;
	vec.push_back(-1000000001); // 처음에 입력 가능한 수열의 원소보다 작은 수를 삽입(처음 원소를 항상 삽입하기 위해)
	for (int i = 1; i <= N; i++) {
		int val;
		cin >> val;
        input.push_back(val);
	    if (vec.back() >= val) {
		    // lower_bound: 찾으려는 val(key) 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지를 리턴(반환형: iterator)
		    int lb = lower_bound(vec.begin(), vec.end(), val) - vec.begin();  // 인덱스 구하기
		    vec[lb] = val; // 최적의 위치에 val 삽입
            idx[i] = lb; 
	    }
	    else { // vec.back() < val 이면  
		    vec.push_back(val); // 삽입
		    len++; // 길이 증가
            idx[i] = vec.size() - 1;
	    }
	}
	cout << len << "\n";
	int index = len;
    for (int i = N; i >= 1; i--){
        if (index == idx[i]) {
            ans.push(input[i - 1]);
			index--;
		}
        if (index == 0) {
            break;
        }
    }
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << "\n";
	return 0;
}