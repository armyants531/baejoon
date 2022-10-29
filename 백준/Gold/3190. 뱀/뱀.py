from collections import deque

# 뱀을 덱으로 구현
snake = deque()
# 보드의 크기 N
N = int(input())
#사과의 개수 K
K = int(input())
# 사과 위치를 나타내는 2차원 리스트
apple = [list(map(int, input().split())) for i in range(K)]

#뱀의 방향 변환 횟수 L
L = int(input())
# 뱀의 방향 전환 정보를 나타내는 2차원 리스트
turn_info = [list(input().split()) for i in range(L)]

# 문자 -> 정수로 형변환(안 하면 방향 전환 안 됨)
for i in turn_info:
    i[0] = int(i[0])

#게임 시간
T = 0
# 뱀의 현재 방향
direction = 0 
# 뱀의 머리 위치
head = [1, 1]

# index of turn_info rotation time 
ti = 0

# 머리 위치 저장
snake.append([head[0], head[1]])
    
while(True):
    T += 1
    # 뱀의 방향
    if direction == 0: # right
        head[1] += 1 
    elif direction == 1: # down
        head[0] += 1
    elif direction == 2: # left
        head[1] -= 1
    elif direction == 3: # up
        head[0] -= 1
        
    # collision
    if head[0] > N or head[1] > N or head[0] < 1 or head[1] < 1: # 벽에 충돌
        print(T)
        break
    elif head in snake: # 자신의 몸에 충돌
        print(T)
        break
    
    # meeting apple
    if head in apple:
        apple.remove(head)
    else: # not meeting apple
        snake.popleft()
    
    # 머리 위치 저장
    snake.append([head[0], head[1]])
    
    # 방향 전환 처리
    if ti < L and T == turn_info[ti][0]: # 인덱스 범위 넘기지 않도록 조건 설정
        if turn_info[ti][1] == 'L': # left
            if direction != 0:
                direction -= 1
            else:
                direction = 3
        else:                       # right
            if direction != 3: 
                direction +=1
            else:
                direction = 0
        ti += 1