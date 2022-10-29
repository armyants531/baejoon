import copy

cctv = [] # [cctv번호, x좌표, y좌표] 저장
graph = [] # 사무실 각 칸의 정보 저장
cctv_mode = [[], [[0], [1], [2], [3]], [[0, 2], [1, 3]], [[0,1], [1,2], [2,3], [3,0]], [[0,1,2],[1,2,3],[2,3,0],[3,0,1]], [[0,1,2,3]]] # 상, 우, 하, 좌: 0, 1, 2, 3

# 상, 우, 하, 좌
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

def supervise(graph, cctv_num_i, x, y):
    for i in cctv_num_i:
        nx = x
        ny = y
        while True:
            nx += dx[i]
            ny += dy[i]
            if not (m > nx >= 0 and n > ny >= 0) or graph[ny][nx] == 6:
                break
            else:
                if graph[ny][nx] == 0:
                    graph[ny][nx] = -1 #감시된 부분 표시 

def dfs(depth, graph):
    global min_val
    if depth == len(cctv): #모든 cctv 감시 구역을 표시했으면 사각지대 칸 수 세기 
        cnt = 0 
        for i in range(n):
            cnt += graph[i].count(0) # count 함수 이용
        min_val = min(min_val, cnt)
        return
    temp = copy.deepcopy(graph)
    cctv_num, x, y = cctv[depth]
    for i in cctv_mode[cctv_num]:
        supervise(temp, i, x, y)
        dfs(depth+1, temp) #다음 cctv로 dfs진행
        temp = copy.deepcopy(graph) #모든 cctv 탐색 후(return 이후) 그래프 초기화 -> 다음 i로 넘어감  

n, m = map(int, input().split())
for i in range(n):
    row_data = list(map(int, input().split()))
    graph.append(row_data)
    for j in range(m):
        if row_data[j] >= 1 and row_data[j] <= 5:
            cctv.append([row_data[j], j, i])

min_val = 64 #최대 사각지대 칸 수
dfs(0, graph)
print(min_val) 