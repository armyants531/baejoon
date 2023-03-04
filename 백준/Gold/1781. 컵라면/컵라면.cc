// https://excited-hyun.tistory.com/61 참고
#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1; // deadline 기준
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2; // cnt 기준
queue<pair<int, int>> temp; // temp 
int t = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  int tot = 0;
  int deadline, cnt;
  for (int i = 0; i < N; i++) {
    cin >> deadline >> cnt;
    pq1.push({deadline, cnt});
  }
  while (!pq1.empty()) {
    deadline = pq1.top().first;
    cnt = pq1.top().second;
    pq1.pop();
    if (t < deadline) { // 현재 시간보다 데드라인 작으면
      t++;
      tot += cnt;
      pq2.push({cnt, deadline}); // 일단 풀기
    }
    else if (!pq2.empty()) { // deadline >= t && pq2 
      int sum = 0;
      // t - deadline + 1개의 문제와 이번 문제의 가치 비교
      for (int i = 0; i < t - deadline + 1; i++) {
          int c = pq2.top().first;
          sum += c;
          int dl = pq2.top().second; 
          pq2.pop();
          temp.push({c, dl});
      }
      if (sum <= cnt) { // 문제 풀기
        tot += cnt;
        tot -= sum;
        t = deadline;
        pq2.push({cnt, deadline});
        while (!temp.empty()) {
          temp.pop();
        }
      }
      else { // 문제 안 풀기
        while(!temp.empty()) {
          pair<int, int> p = temp.front();
          temp.pop();
          pq2.push(p);
        }
      }
    }
  }
  cout << tot << "\n";
}