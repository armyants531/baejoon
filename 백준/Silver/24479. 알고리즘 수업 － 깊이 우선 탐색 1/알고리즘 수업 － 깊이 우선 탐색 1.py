#24479 #알고리즘 수업 - 깊이 우선 탐색 1
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 8) # 한계 확장

n, m, r = map(int, input().split()) # 정점의 수: n, 간선의 수: m, 시작 정점: r

order = 1 # 방문 순서 
visited = [0] * (n+1) # 방문 리스트에 정점 방문 순서 적기
graph = [[] for _ in range(n+1)] # 2차원 배열 형성
for i in range(m): # 간선의 수 만큼 입력
  a, b = map(int, input().split())
  #그래프 연결 정보 추가하기
  graph[a].append(b)
  graph[b].append(a)

for i in range(1, n+1):
  graph[i].sort() # 오름차순으로 방문 -> 정렬 필요 

def dfs(R):
  global order
  visited[R] = order  
  for i in graph[R]:
    if visited[i] == 0: # 방문 아직 안 했으면  
      order += 1
      dfs(i)

dfs(r) 

for i in range(1, n+1):
  print(visited[i]) 
