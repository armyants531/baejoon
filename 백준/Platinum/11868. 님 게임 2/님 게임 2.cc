#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	long long xorNum;
	long long arr[1000] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// xor 취하기
	xorNum = arr[0];
	for (int i = 1; i < n; i++) {
		xorNum = xorNum ^ arr[i];
	}
	if (xorNum == 0) { // 모든 수를 xor을 취한 값(Nim sum)이 0이면 koosaga의 패배 
		cout << "cubelover" << "\n";
	}
	else { // 아닌 경우 항상 Nim-sum을 0이 되도록 맞추어 줄 수 있으므로 koosaga의 승리  
		cout << "koosaga" << "\n";
	}
}