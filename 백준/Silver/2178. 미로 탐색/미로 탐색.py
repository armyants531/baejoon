from collections import deque

n, m = map(int, input().split())

graph = []
for i in range(n):
  graph.append(list(map(int, input())))

def bfs(a, b):
  queue = deque()
  queue.append((a, b))
  # 큐가 빌 때 까지 반복
  while queue:
    # 큐에서 하나의 원소를 뽑아 이에 해당하는 그래프의 위치에서 네 방향을 확인 
    tuple1 = queue.popleft()
    x = tuple1[0]
    y = tuple1[1]
    for i in range(4):
      if i == 0: # 상
        X = x - 1
        Y = y
      elif i == 1: # 하
        X = x + 1
        Y = y
      elif i == 2: # 좌
        X = x
        Y = y - 1
      else: # 우
        X = x
        Y = y + 1
      
      if X < 0 or X >= n or Y < 0 or Y >= m: # 범위 초과
        continue
      else: 
        if graph[X][Y] == 0: # 이동할 수 없는 칸인 경우
          continue
        else:
          if graph[X][Y] == 1: # 처음 도착한 곳 일 때
            graph[X][Y] = graph[x][y] + 1
            queue.append((X, Y))
  return graph[n-1][m-1] 
           
print(bfs(0,0))