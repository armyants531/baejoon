// 데이터 순서 복원  // ad-hoc
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int N;
  cin >> N;
  vector<int> A, B, C;
  vector<int> idx1(N + 1), idx2(N + 1), idx3(N + 1);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A.push_back(a);
    idx1[a] = i; 
  }
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    B.push_back(a);
    idx2[a] = i;
  }
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    C.push_back(a);
    idx3[a] = i;
  }
  bool allDiffEx = false;
  int i1, i2, i3;
  for (int i = 1; i <= N; i++) {
    if (idx1[i] != idx2[i] && idx2[i] != idx3[i] && idx3[i] != idx1[i]) {
      allDiffEx = true;
      if (idx1[i] < idx2[i] && idx1[i] < idx3[i]) {
        if (idx2[i] < idx3[i]) {
          A.erase(A.begin() + idx1[i]);
          A.insert(A.begin() + idx2[i], i);
        }
        else {
          A.erase(A.begin() + idx1[i]);
          A.insert(A.begin() + idx3[i], i);
        }
        for (int i = 0; i < N; i++) {
          cout << A[i] << " ";
        }
      }
      else if (idx2[i] < idx1[i] && idx2[i] < idx3[i]) {
        if (idx1[i] < idx3[i]) {
          B.erase(B.begin() + idx2[i]);
          B.insert(B.begin() + idx1[i], i);
        } 
        else {
          B.erase(B.begin() + idx2[i]);
          B.insert(B.begin() + idx3[i], i);
        }
        for (int i = 0; i < N; i++) {
          cout << B[i] << " ";
        }
      }
      else if (idx3[i] < idx1[i] && idx3[i] < idx2[i]) {
        if (idx1[i] < idx2[i]) {
          C.erase(C.begin() + idx3[i]);
          C.insert(C.begin() + idx1[i], i);
        }
        else {
          C.erase(C.begin() + idx3[i]);
          C.insert(C.begin() + idx2[i], i);
        }
        for (int i = 0; i < N; i++) {
          cout << C[i] << " ";
        }
      }
      break;      
    }
  }

  if (!allDiffEx) {
    vector<int> ans(N);
    for (int i = 1; i <= N; i++) {
      if (idx1[i] == idx2[i]) {
        ans[idx1[i]] = i;
      }
      else if (idx2[i] == idx3[i]) {
        ans[idx2[i]] = i;
      }
      else {
        ans[idx3[i]] = i;
      }
    }
    for (int i = 0; i < N; i++) {
      cout << ans[i] << " ";
    }
  }

	return 0;
}