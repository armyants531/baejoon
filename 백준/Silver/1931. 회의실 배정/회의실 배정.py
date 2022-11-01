# 1931 회의실 배정 # 3번 째 시도
n = int(input())
max_num = 0
meeting_list = []

# 정보 입력 받기
for i in range(n):
  temp = list(map(int, input().split()))
  meeting_list.append(temp)

meeting_list.sort(key = lambda x: (x[1], x[0])) # 1. 종료 시간에 대해 오름차순으로 정렬, 2. 시작 시간에 대해 오름차순으로 정렬

end = 0
for i, j in meeting_list:
  if i >= end:# 추가하고 싶은 회의 시작 시간이 최근 회의 종료 시간보다 크거나 같은 경우
    end = j # 종료 시간 변경
    max_num += 1

print(max_num)