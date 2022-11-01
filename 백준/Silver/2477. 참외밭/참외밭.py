#2477 #참외밭
# 육각형의 넓이 = 가장 긴 세로변 x 가장 긴 가로변 - 앞선 두 변에 인접하지 않은 두 변의 곱  
K = int(input())
max_height = 0 
max_width = 0
info_list = []
max_height_idx = 0
max_width_idx = 0

for i in range(6):
  temp_info = list(map(int, input().split()))
  info_list.append(temp_info)

  if temp_info[0] == 3 or temp_info[0] == 4: # 세로변인 경우
    if temp_info[1] > max_height:
      max_height = temp_info[1]
      max_height_idx = i

  if temp_info[0] == 1 or temp_info[0] == 2: # 가로변인 경우
    if temp_info[1] > max_width:
      max_width = temp_info[1]
      max_width_idx = i

# 가장 긴 두 변에 인접하지 않은 두 변의 곱 구하기
# 인접한 두 변의 인덱스와 가장 긴 두 변의 인덱스로 구성된 리스트 생성
idx1 = (max_height_idx - 1) % 6 
idx2 = (max_height_idx + 1) % 6
idx3 = (max_width_idx - 1) % 6
idx4 = (max_width_idx + 1) % 6
index_list = [idx1, idx2, idx3, idx4]
# 인접하지 않은 두 변의 인덱스로 구성된 리스트 생성
index_list2 = [] 

for i in range(6):
  if i not in index_list:
    index_list2.append(i)

line1 = info_list[index_list2[0]][1]
line2 = info_list[index_list2[1]][1]
area = max_height * max_width - line1 * line2
print(K * area)