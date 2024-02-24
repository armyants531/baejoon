def solution(triangle):
    answer = 0;
    
    height = len(triangle)  # 세로 크기
    
    i = 1
    for i in range(1, height):
        t = len(triangle[i])
        for j in range(t):  
            if j == 0:  # 왼쪽 모서리 인덱스인 경우
                triangle[i][j] += triangle[i-1][j]
            elif j == t - 1:  # 오른쪽 모서리 인덱스인 경우
                triangle[i][j] += triangle[i-1][j-1]
            else:
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j])
                
        answer = max(triangle[height-1])
    return answer