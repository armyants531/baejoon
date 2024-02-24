#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int h = triangle.size();
    for (int i = 1; i < h; i++) {
        triangle[i][0] += triangle[i-1][0];
        for (int j = 1; j < i; j++) {
            triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
        }
        triangle[i][i] += triangle[i-1][i-1];
    }      
    for (int i = 0; i < h; i++) {
        answer = max(answer, triangle[h-1][i]);
    }
    return answer;
}