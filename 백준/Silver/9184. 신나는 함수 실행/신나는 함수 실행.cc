// Function Run Fun  // memoization
#include <algorithm>
#include <iostream>

using namespace std;

long long table[21][21][21] = {0,}; // 1 <= num <= 20
bool visited[21][21][21] = {0,};

long long w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    else if (visited[a][b][c] == true) // out of bound를 막기 위해 3번째 조건문으로 배치
        return table[a][b][c];
    else if (a < b && b < c) {
        visited[a][b][c] = true; // 방문 표시
        return table[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } 
    else {
        visited[a][b][c] = true;
        return table[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    while (!(a == -1 && b == -1 && c == -1)) {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";

        cin >> a >> b >> c;
    }

    return 0;
}