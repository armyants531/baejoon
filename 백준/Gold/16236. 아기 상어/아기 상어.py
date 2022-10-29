from collections import deque
import heapq

time = 0
size = 2
eaten_fish_num = 0

n = int(input())
space = [list(map(int, input().split())) for i in range(n)]

for y in range(n):
    for x in range(n):
        if space[y][x] == 9:
            start = (0, y, x)

def find_min(start, space, size):
    dirs = [(0, 1), (0, -1), (-1, 0), (1, 0)]
    queue = deque()
    queue.append(start)

    cnt, y, x = start # cnt = 다음 물고기를 먹는데 걸리는 시간 = 거리
    # 시작하는 위치의 값을 0으로 바꾸기
    space[y][x] = 0
    min_dist = [] # (cnt, y, x) 형태로 저장할 heapq
    visited = set()

    while queue:
        cnt, y, x = queue.popleft()
        visited.add((y, x))
        for dy, dx in dirs:
            ny, nx = y + dy, x + dx
            if 0 <= ny < n and 0 <= nx < n and (ny, nx) not in visited: # 공간의 범위 내에 있고 아직 방문하지 않았으면
                visited.add((ny, nx))                
                if space[ny][nx] == size or space[ny][nx] == 0: # 같은 크기의 물고기가 있거나 빈칸인 경우
                    queue.append((cnt + 1, ny, nx))
                    continue
                if space[ny][nx] > size: # 큰 물고기가 있으면 
                    continue
                else: # 작은 크기의 물고기가 있으면
                    heapq.heappush(min_dist, (cnt + 1, ny, nx))
      
    # 먹을 수 있는 가장 가까운 물고기 까지의 거리 정보
    if min_dist:
        return min_dist[0]
    else:
        return None # 식용 가능 물고기 x

while True:
    next_dist = find_min(start, space, size)

    if next_dist is None:
        break
    cnt, y, x = next_dist
    time += cnt
    # 물고기 먹은 수와 상어의 크기 관계
    eaten_fish_num += 1
    if eaten_fish_num == size:
        eaten_fish_num = 0 # 초기화
        size += 1 # 크기 증가
  
    # 출발점 변경
    start = (0, y, x)

print(time)