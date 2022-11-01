N = int(input())

schedule = [list(map(int, input().split())) for i in range(N)]     
profit = []

for i in range(N+1):
    profit.append(0)
        
for i in range(N,0,-1): # 뒤에서 부터 스케줄 짜기
    if i - 1 + schedule[i-1][0] <= N: # 스케줄 추가 가능시
        profit[i-1] = max(schedule[i-1][1] + profit[i-1 + schedule[i-1][0]], profit[i])
    else:
        profit[i-1] = profit[i]

print(profit[0])