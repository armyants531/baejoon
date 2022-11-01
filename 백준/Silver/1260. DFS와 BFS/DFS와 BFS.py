from collections import deque

def dfs(graph, v, visited):
  #현재 노드를 방문 처리
  visited[v] = True
  print(v, end = ' ')
  #현재 노드와 연결된 다른 노드를 재귀적으로 방문
  for i in graph[v]:
    if not visited[i]:
      dfs(graph, i, visited)

def bfs(graph, v, visited):
  queue = deque([v])
  #현재 노드를 방문 처리
  visited[v] = True
  # 큐가 빌 때 까지 반복
  while queue:
    # 큐에서 하나의 원소를 뽑아 출력
    v1 = queue.popleft()
    print(v1, end = ' ')

    # 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
    for i in graph[v1]:
      if not visited[i]:
        queue.append(i)
        visited[i] = True

N, M, V = map(int, input().split())

graph = [[] for i in range(N+1)]

# 각 노드가 방문된 정보
visited_1 = [False for i in range(N+1)]
visited_2 = [False for i in range(N+1)]
# 간선 정보로 부터 graph 정보 채우기
for i in range(M):
  v1, v2 = map(int, input().split())
  graph[v1].append(v2)
  graph[v2].append(v1)

# 오름차순으로 정렬
for i in range(1, N+1):
  graph[i].sort()

# DFS 함수 호출
dfs(graph, V, visited_1)
print()
# BFS 함수 호출
bfs(graph, V, visited_2)